#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
给你一个字符串 s，找到 s 中最长的回文子串

如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。
输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。

方法一：暴力
暴力：枚举所有子串，判断是否是回文串
时间复杂度 O(n^2 * log(n))

方法二：动态规划
对于一个子串，如果是回文串，那么去掉两端的字符后，仍然是回文串
这属于重叠子问题，可以用动态规划解决
定义 dp[i][j] 表示 s[i, j] 是否是回文串
如果 s[i] == s[j]，并且 s[i+1, j-1] 是回文串，那么 s[i, j] 也是回文串

考虑如何枚举：
枚举子串的长度，然后枚举子串的起点
则终点为 i + len - 1
此时状态转移方程为：dp[i][j] = dp[i+1][j-1] && s[i] == s[j

方法三：中心扩展
由于 dp[i][j] 需要依赖 dp[i+1][j-1]，所以可以考虑从中心向两边扩展
枚举中心点，然后向两边扩展

但是有两种边界情况：子串长度为 1，子串长度为 2
枚举这两种情况，然后向两边扩展，取最长的回文串

方法三：Manacher 马拉车
时间复杂度 O(n)

https://leetcode.cn/problems/longest-palindromic-substring/solutions/255195/zui-chang-hui-wen-zi-chuan-by-leetcode-solution/
 */
class SolutionExpand {
  typedef pair<int, int> pii;

 public:
  string longestPalindrome(string s) {
    int n = s.size();
    if (n == 1) {
      return s;
    }
    function<pii(int, int)> expandAroundCenter = [&](int l, int r) {
      while (l >= 0 && r < n && s[l] == s[r]) {
        ++r;
        --l;
      }
      return make_pair(l + 1, r - 1);  // 回文串的左右边界 [l, r]
    };

    int start = 0, end = 0;
    for (int i = 0; i < n; i++) {
      auto [l1, r1] = expandAroundCenter(i, i);
      auto [l2, r2] = expandAroundCenter(i, i + 1);
      if (r1 - l1 > end - start) {
        start = l1;
        end = r1;
      }
      if (r2 - l2 > end - start) {
        start = l2;
        end = r2;
      }
    }
    return s.substr(start, end - start + 1);
  }
};

class Solution {
 public:
  string longestPalindrome(string s) {
    int n = s.size();
    if (n == 1) {
      return s;
    }
    int maxLen = 1, start = 0;
    vector<vector<int>> dp(n, vector<int>(n));          //
    for (int i = 0; i < n; i++) {                       //
      dp[i][i] = 1;                                     // 单个字符是回文串
    }                                                   //
                                                        //
    for (int len = 2; len <= n; len++) {                //
      for (int i = 0; i < n && i + len - 1 < n; i++) {  //
        int j = i + len - 1;                            //
        if (s[i] == s[j]) {                             // 首尾字符相同
          if (len <= 2) {                               // 两个字符无法取到 s[i+1, j-1]
            dp[i][j] = 1;                               //
          } else {                                      //
            dp[i][j] = dp[i + 1][j - 1];
          }
        }

        if (dp[i][j] && len > maxLen) {
          maxLen = len;
          start = i;
        }
      }
    }
    return s.substr(start, maxLen);
  }
};
int main() {

  Solution test;
  string s = "cbbd";
  cout << test.longestPalindrome(s) << endl;
  return 0;
}