#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
/* 
给你一个长度为 n 下标从 0 开始的整数数组 nums 和一个 正奇数 整数 k 。

x 个子数组的能量值定义为 
strength = sum[1] * x - sum[2] * (x - 1) + sum[3] * (x - 2) - sum[4] * (x - 3) + ... + sum[x] * 1 ，其中 sum[i] 是第 i 个子数组的和。
更正式的，能量值是满足 1 <= i <= x 的所有 i 对应的 (-1)^{i+1} * sum[i] * (x - i + 1) 之和。

你需要在 nums 中选择 k 个 不相交子数组 ，使得 能量值最大 。

请你返回可以得到的 最大能量值 。

注意，选出来的所有子数组 不 需要覆盖整个数组。

1 <= n <= 1e4

方法一：动态规划
dp[i][j][k] 表示选择 i 到 j 

 */
class Solution {
  typedef long long ll;

 public:
  long long maximumStrength(vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(k + 1, vector<ll>(2, INT_MIN)));
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;
    for (int i = 1; i <= n; i++) {

      for (int j = 1; j <= k; j++) {
        if (dp[i - 1][j - 1][0] == INT_MIN && dp[i - 1][j - 1][1] == INT_MIN) {
          break;
        }
        ll sum = (k - j + 1) * ((j & 1) ? nums[i - 1] : -nums[i - 1]);
        dp[i][j][0] = max(max(dp[i - 1][j - 1][0] + sum, dp[i - 1][j - 1][1] + sum), dp[i - 1][j][0] + sum);
        dp[i][j][1] = max(max(dp[i][j][0], dp[i - 1][j][1]), dp[i - 1][j][0]);
      }
    }
    return max(dp[n][k][0], dp[n][k][1]);
  }
};
int main() {

  Solution test;
  vector<int> a = {1, 2, 3, -1, 2};
  int k = 3;
  cout << test.maximumStrength(a, k);
  return 0;
}