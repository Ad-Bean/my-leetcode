
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。

输入：n = 13
输出：6

输入：n = 0
输出：0

0 <= n <= 1e9

方法一：数位 DP

将 n 转成字符串 s
f(i, cnt, isLimit, isNum) 表示构造从左往右构造第 i 位，已经出现了 cnt 个 1
cnt 表示前面填了几个 1
isLimit 表示当前是否受到了 n 的约束，是则第 i 位填入的数字最多为 s[i]，否则可以是 9，如果受到约束，则后续的也是约束
isNum 表示是否是数字，否则跳过，

无需前导零，仅需要 f(i, cnt, isLimit)

数位 DP 过程：
假设 n = 13, f(0, 0, true)
i = 0, 第一位受限制，枚举 [0, 1]
- 第一位为 0
    i = 1, 枚举第二位为 [0, 9]
- 第一位为 1, 第二位受限制, 
    i = 1, 枚举第二位为 [0, 3]

由于会不断回溯到第 i 位，可以记忆化对第 i 位，如果前面数字 1 的个数已经统计过，则直接返回
 */
class Solution {
 public:
  int countDigitOne(int n) {
    string s = to_string(n);
    int m = s.size();
    vector<vector<int>> dp(m, vector<int>(m, -1));
    // int dp[m][m];  // 记忆化
    // memset(dp, -1, sizeof(dp));
    function<int(int, int, bool)> f = [&](int i, int cnt, bool isLimit) -> int {
      if (i == m) {
        return cnt;
      }
      if (!isLimit && dp[i][cnt] >= 0) {
        return dp[i][cnt];
      }
      int res = 0;
      for (int d = 0, up = isLimit ? s[i] - '0' : 9; d <= up; d++) {
        res += f(i + 1, cnt + (d == 1), isLimit && d == up);
      }
      if (!isLimit) {
        dp[i][cnt] = res;
      }
      return res;
    };
    return f(0, 0, true);
  }
};
int main() {

  Solution test;
  cout << test.countDigitOne(1234) << endl;
  return 0;
}