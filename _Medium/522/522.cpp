#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给定字符串列表 strs ，返回其中 最长的特殊序列 的长度。如果最长特殊序列不存在，返回 -1 。

特殊序列 定义如下：该序列为某字符串 独有的子序列（即不能是其他字符串的子序列）。

 s 的 子序列可以通过删去字符串 s 中的某些字符实现。

例如，"abc" 是 "aebdc" 的子序列，因为您可以删除"aebdc"中的下划线字符来得到 "abc" 。
"aebdc"的子序列还包括"aebdc"、 "aeb" 和 "" (空字符串)。
 
输入: strs = ["aba","cdc","eae"]
输出: 3
解释: 最长特殊序列可为 "aba"，"cdc" 或 "eae" ，这三个字符串都是独特的子序列。

输入: strs = ["aaa","aaa","aa"]
输出: -1
解释: 所有的字符串都具有相同的子序列

2 <= strs.length <= 50
1 <= strs[i].length <= 10
strs[i] 只包含小写英文字母

方法一：
初看以为是 LCS，但并不是简单的 dp[i][j] = dp[i-1][j-1] + 1 if s1[i] == s2[j] 的问题

暴力：枚举所有字符串，找到所有的子序列，然后判断是否是独特的

其中可以优化的地方：
如果一个字符串 strs[i] 长于其他，那么 strs[i] 一定是独特的，其他字符串的子序列一定不包含它

同时，对于 strs[i] 如果一个子序列是特殊序列，那么 strs[i] 本身一定是特殊序列
> 因为子序列是通过删除字符得到的，特殊序列往上增加一定也是特殊序列

所以只需要枚举所有字符串，判断 strs[i] 是否是其他字符串的特殊序列即可
问题转成：如何判断 str[i] 是否是 str[j] 的子序列

贪心 + 双指针
int l = 0, r = 0;
if (strs[i][l] == strs[j][r]) {
    l++, r++;
} else {
    r++;   // 只移动 r
}
如果 l 移动到末尾，说明 str[i] 是 str[j] 的子序列

优化：
按照字符串长度从大到小排序 strs，然后枚举所有字符串，如果是特殊序列，直接返回
找个最长的 -> 一定是特殊序列
没有最长的 -> 回落到 O(n^2 * len) 
 */
class Solution {
 public:
  int findLUSlength(vector<string>& strs) {
    function<bool(string&, string&)> isSubsequence = [&](string& a, string& b) -> bool {
      int l = 0, r = 0;
      int n = a.size(), m = b.size();
      while (l < n && r < m) {
        if (a[l] == b[r]) {
          l++, r++;
        } else {
          r++;
        }
      }
      return l == n;
    };

    sort(strs.begin(), strs.end(), [&](const string& a, const string& b) { return a.size() > b.size(); });

    int n = strs.size();
    int ans = -1;

    for (int i = 0; i < n; i++) {
      bool flag = true;
      for (int j = 0; j < n; j++) {
        if (i != j && isSubsequence(strs[i], strs[j])) {
          flag = false;
          break;
        }
      }
      if (flag) {
        return strs[i].size();
      }
    }
    return -1;
  }
};
int main() {

  Solution test;
  return 0;
}
