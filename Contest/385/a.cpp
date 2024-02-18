#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个下标从 0 开始的字符串数组 words 。

定义一个 布尔 函数 isPrefixAndSuffix ，它接受两个字符串参数 str1 和 str2 ：

当 str1 同时是 str2 的前缀（prefix）和后缀（suffix）时，isPrefixAndSuffix(str1, str2) 返回 true，否则返回 false。
例如，isPrefixAndSuffix("aba", "ababa") 返回 true，因为 "aba" 既是 "ababa" 的前缀，也是 "ababa" 的后缀，但是 isPrefixAndSuffix("abc", "abcd") 返回 false。

以整数形式，返回满足 i < j 且 isPrefixAndSuffix(words[i], words[j]) 为 true 的下标对 (i, j) 的 数量 。
 

 */
class Solution {
 public:
  int countPrefixSuffixPairs(vector<string>& words) {
    int n = words.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int len1 = words[i].size();
      for (int j = i + 1; j < n; j++) {
        int len2 = words[j].size();
        if (len1 > len2) {
          continue;
        }
        string pre = words[j].substr(0, len1);
        if (pre != words[i]) {
          continue;
        }
        string suf = words[j].substr(len2 - len1, len1);
        if (pre == suf) {
          ans++;
        }
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  vector<string> words = {"pa", "papa", "ma", "mama"};
  cout << test.countPrefixSuffixPairs(words) << endl;
  return 0;
}