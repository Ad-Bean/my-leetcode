#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

/* 
给你一个下标从 0 开始的字符串 s 、字符串 a 、字符串 b 和一个整数 k 。

如果下标 i 满足以下条件，则认为它是一个 美丽下标：

0 <= i <= s.length - a.length
s[i..(i + a.length - 1)] == a
存在下标 j 使得：
0 <= j <= s.length - b.length
s[j..(j + b.length - 1)] == b
|j - i| <= k
以数组形式按 从小到大排序 返回美丽下标。


1 <= k <= s.length <= 1e5
方法一：二分 + 滑动窗口 
substr 求出 a 在 s 中所有位置 aa 
substr 求出 b 在 s 中所有位置 bb 
此时 时间复杂度是 On^2
遍历 aa 中的下标 i，在 bb 中二分查找距离 i 最近的 j，如果 abs(i - j) <= k 则记录答案

1 <= k <= s.length <= 5e5
方法二：KMP + 二分 / 滑窗
时间复杂度 Onlgn / On
在文本 text 中找到模式串 pattern 返回所有匹配的位置开头
 */
class Solution {
 public:
  vector<int> beautifulIndices(string s, string a, string b, int k) {
    int n = s.size();
    // i in [0, dif] and s[i: i + a.size() - 1] == a
    // and j exists, if j in [0, dif] and s[j: j + b.size() - 1] == b, |j - i| <= k
    // in order return i
    int lena = a.size(), lenb = b.size();
    vector<int> ii, jj;
    for (int i = 0; i < n; i++) {
      if (i <= n - lena && s.substr(i, lena) == a) {
        ii.emplace_back(i);
      }
      if (i <= n - lenb && s.substr(i, lenb) == b) {
        jj.emplace_back(i);
      }
    }

    vector<int> ans;
    for (const int i : ii) {
      int idx = lower_bound(jj.begin(), jj.end(), i) - jj.begin();
      if (idx >= 0 && idx < jj.size() && abs(i - jj[idx]) <= k) {
        ans.emplace_back(i);
      } else if (idx - 1 >= 0 && idx - 1 < jj.size() && abs(i - jj[idx - 1]) <= k) {
        ans.emplace_back(i);
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