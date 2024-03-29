
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。

如果不存在 公共子序列 ，返回 0 。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。

输入：text1 = "abcde", text2 = "ace" 
输出：3  
解释：最长公共子序列是 "ace" ，它的长度为 3 。

方法一：动态规划
最长公共子序列问题是典型的二维动态规划问题。
dp[i][j] 表示 text1[:i] 和 text2[:j] 的最长公共子序列长度

dp[0][:] = 0
dp[:][0] = 0

如果 text1[i] == text2[j] 则
dp[i][j] = dp[i-1][j-1] + 1

如果 text1[i] != text2[j] 则考虑两种情况 
text1[i-1] 和 text2[j]
text1[i] 和 text2[j-1]
dp[i][j] = max(dp[i-1][j], dp[i][j-1])

 */
class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    // dp[0][:] = 0, dp[:][0] = 0
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[n][m];
  }
};
int main() {

  Solution test;
  return 0;
}