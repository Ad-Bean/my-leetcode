#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
暴力从 0-10 出发，每个数有最多两个分叉，2^n 时间复杂度，但 n <= 5000，不可行

n = 1，ans = 10
n = 2, ans = 20 可以从 n = 1 推导
dp[i][j] 表示从数字 i 开始，走 j 步可以得到 j+1 位数字的个数
dp[0][1] = dp[4][0] + dp[6][0] = 2，从 0 开始走 1 步可以得到 2 个 2 位数
dp[1][n] = dp[6][n-1] + dp[8][n-1] 
 */

class Solution {
 public:
  int knightDialer(int n) {
    const int mod = 1e9 + 7;
    vector<vector<int>> dirs = {
        {4, 6},     // 0 可以从 4 或者 6 出发得到
        {6, 8},     //
        {7, 9},     //
        {4, 8},     //
        {3, 9, 0},  // 4
        {},         //
        {1, 7, 0},  // 6
        {2, 6},     //
        {1, 3},     //
        {2, 4},     //
    };
    // vector<vector<int>> dp(10, vector<int>(2));  // [10][2] 滚动数组
    vector<int> dp1(10, 1);
    for (int i = 0; i < n - 1; i++) {
      vector<int> dp2(10);
      for (int j = 0; j < 10; j++) {
        for (const int& next : dirs[j]) {
          dp2[next] += dp1[j];
          dp2[next] %= mod;
        }
      }
      dp1 = dp2;
    }
    int ans = 0;
    for (int i = 0; i < 10; i++) {
      ans = (ans + dp1[i]) % mod;
    }
    return ans % mod;
  }
};
int main() {

  Solution test;
  return 0;
}