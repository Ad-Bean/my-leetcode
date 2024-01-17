#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

/* 
在 text 中找到 pattern 出现的下标
KMP 时，匹配失败不需要回退 text，只需要回退 pattern 并且尽可能少地回退，回退位置前面的一段已经匹配 text
本质就是用 text 的头部匹配 pattern 的尾部，找共同前后缀
比如 
abbaabbaaba
abbaaba

abbaab 前缀 a ab abb abba abbaa 不包含最后一个字符
abbaab 后缀 b ab aab baab bbaab 不包含第一个字符
最长共同前后缀是 ab, text 不回退时，pattern 回退到第三个字符

计算 pattern 的最长公共前后缀，
abababzababab 
0012340123456?
a ab aba abab ababa ababab abababz abababza abababzab abababzaba abababzabab abababzababa abababzababab 
b ab bab abab babab ababab zababab bzababab ...
对每个子字符串 [0...i]，算出其「相匹配的真前缀与真后缀中，最长的字符串的长度」
所以子字符串 abababzababab 的真前缀和真后缀 **最大匹配** 了 6 个（ababab），那 **次大匹配** 了多少呢
**次大匹配** 必定在最大匹配 ababab 中，所以 **次大匹配** 数就是 ababab 的最大匹配数 4
第三大的匹配数同理，在 abab 中找到第三大匹配数 2
此时计算问号处，由于此时最长匹配数是 6 即 ababab，下一位是 z 但 s[i] 最后一位并不是 z，
回到次长，abab 下一个是 a，则此时最大匹配数是 5

所以计算时，维护一个最长的匹配数：
如果最长匹配串的最后一个字符和当前字符不相同：
一直回到次长、次次长，即 maxLength = maxMatchLengths[maxLength - 1]，直到 maxLength = 0 为止

如果最长匹配串的下一个字符和当前字符相同，
比如对于 ababa 最后一位，此时最长匹配是 abab, 下一个是 a 和最后一个 a 相同，则 maxLength++, maxLengths[i] = maxLength
vector<int> next = vector<int>(pattern.size());
int maxlen = 0;
for (int i = 1; i < pattern.size(); i++) {
  while (maxlen > 0  && pattern[maxlen] != pattern[i]) {
    maxlen = next[maxlen - 1];
  }
  if (pattern[maxlen] == pattern[i]) {
    maxlen++;
  }
  next[i] = maxlen;
}
时间复杂度：O(n)

KMP 匹配过程和求最大匹配数类似，匹配失败时，模式串回到上一个次大的最长共同前后缀
int cnt = 0;
vector<int> idx;
for (int i = 0; i < text.size(); i++) {
  while (cnt>0 && pattern[cnt] != text[i]) {  // 字符不同，回到上一个次大
    cnt = next[cnt - 1];
  }
  if (pattern[cnt] == text[i]) {              // 字符相同，共同前进
    cnt++;
  }
  if (cnt == pattern.size()) {                // 匹配成功
    idx.emplace_back(i - pattern.size() + 1); // 得到第一个匹配的下标
    cnt = next[cnt - 1];                      // 回到上一个次大，重新匹配 
  }
}

方法一：KMP + 二分查找 Onlogn

kmp 求出在 S 中 a 的每个位置 idxa
kmp 求出在 S 中 b 的每个位置 idxb

遍历 a 的每个下标 i，在 idxb 中二分找到第一个大于等于 i 的下标 j，
如果 abs(i - idxb[j]) <= k || abs(i-idxb[j-1]) 即满足 j 存在

方法二：KMP + 双指针 On

由于 idxa idxb 都是有序
枚举 i in idxa, j 应该也往右，

vector<int> ans;
int idx = 0;                                                // 右指针
for (int i = 0; i < len_a; i++) {                           // 左指针
  while(idx < len_b && idx_b[idx] < idx_a[i] - k) {         // 大小为 k 的窗口，j 要往前走到 i-k 的左界
    idx++;
  }
  if (idx < len_b && abs(idx_b[idx] - idx_a[i]) <= k) {     
    ans.emplace_back(i);
  }
}
return ans;

 */
class Solution {
 public:
  vector<int> getNext(string pattern) {
    int n = pattern.size();
    vector<int> next = vector<int>(n);
    int maxlen = 0;
    for (int i = 1; i < n; i++) {
      while (maxlen > 0 && pattern[maxlen] != pattern[i]) {
        maxlen = next[maxlen - 1];
      }
      if (pattern[maxlen] == pattern[i]) {
        maxlen++;
      }
      next[i] = maxlen;
    }
    return next;
  }

  vector<int> kmp(string text, string pattern) {
    int m = text.size();
    int n = pattern.size();
    vector<int> idx;
    vector<int> next = getNext(pattern);

    int maxlen = 0;
    for (int i = 0; i < m; i++) {
      while (maxlen > 0 && pattern[maxlen] != text[i]) {
        maxlen = next[maxlen - 1];
      }
      if (pattern[maxlen] == text[i]) {
        maxlen++;
      }
      if (maxlen == n) {
        idx.emplace_back(i - n + 1);
        maxlen = next[maxlen - 1];
      }
    }
    return idx;
  }

  vector<int> beautifulIndices(string s, string a, string b, int k) {
    vector<int> idx_a = kmp(s, a);
    vector<int> idx_b = kmp(s, b);
    int len_b = idx_b.size();
    vector<int> ans;
    for (const auto i : idx_a) {
      auto j = lower_bound(idx_b.begin(), idx_b.end(), i) - idx_b.begin();  // 在 b 的下标中找到第一个大于等于 i 的
      if ((j < len_b && idx_b[j] - i <= k) || (j - 1 >= 0 && i - idx_b[j - 1] <= k)) {  //
        ans.emplace_back(i);                                                            // j 只需要存在即可
      }
    }
    return ans;
  }
};
int main() {
  Solution test;
  auto ans = test.beautifulIndices("wfvxfzut", "wfv", "ut", 6);
  for (const auto& a : ans) {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}