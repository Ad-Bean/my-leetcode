
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

/* 

给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

方法一：动态规划

dp[i][] 是第 i 天的 累计 利润
dp[i][0] 表示有一只股票
dp[i][1] 表示没有任何股票，在冷冻期
dp[i][2] 表示没有任何股票，不在冷冻期

dp[i][0] = max(dp[i - 1][2] - prices[i], dp[i - 1][0])
dp[i][1] = max(dp[i - 1][0] + prices[i])
dp[i][2] = max(dp[i - 1][1], dp[i-1][2])

空间优化：

dp[i] 只与 dp[i - 1] 有关
int n = prices.size();
int f0 = -prices[0];
int f1 = 0;
int f2 = 0;
for (int i = 1; i < n; ++i) {
    int newf0 = max(f0, f2 - prices[i]);
    int newf1 = f0 + prices[i];
    int newf2 = max(f1, f2);
    f0 = newf0;
    f1 = newf1;
    f2 = newf2;
}

 */
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty()) {
      return 0;
    }
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(3));
    dp[0][0] = -prices[0];
    for (int i = 1; i < n; i++) {
      dp[i][0] = max(dp[i - 1][2] - prices[i], dp[i - 1][0]);  // 有股票
      dp[i][1] = dp[i - 1][0] + prices[i];                     // 没有股票，冷冻
      dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);              // 没有股票，不冷冻
    }
    return max(dp[n - 1][1], dp[n - 1][2]);
  }
};
int main() {

  Solution test;
  return 0;
}