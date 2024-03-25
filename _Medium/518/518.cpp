
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。

请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。

假设每一种面额的硬币有无限个。 

题目数据保证结果符合 32 位带符号整数。
输入：amount = 5, coins = [1, 2, 5]
输出：4
解释：有四种方式可以凑成总金额：
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

方法一：动态规划
相比于 322 题求最少能组成 amount 的硬币数量，518 是求能组成总金额的方案数，
同样使用动态规划
考虑 dp[i] 为组成 i 的方案数
dp[0] = 1
dp[1] = dp[1-1] = 1
dp[2] = dp[2-1] + d[2-2] = 2      // 1+1, 2
dp[3] = dp[3-1] + dp[3-2] = 3     // 1+1+1, 1+2, 2+1
dp[4] = SUM(dp[4 - coins[i]]) = dp[3] + dp[2] = 5  // 1+1+1+1, 1+1+2, 1+2+1
dp[5] = SUM(dp[5 - coins[i]]) = dp[4] + dp[3] + dp[0] = 5 + 3 + 1 = 9

可以发现这样是错误的，dp[3] 开始多枚举了一些状态，变成了排列数而不是 **组合数**
所以要重新考虑状态和转移方程，不关心硬币的使用顺序，而是考虑有没有用到
dp[i][j] 表示使用前 i 个硬币组成金额 j 的方案数
dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]]  // 不用当前硬币 + 使用当前硬币
dp[i-1][j] 表示不使用当前硬币组成 j 的方案数，dp[i][j-coins[i-1]] 表示使用当前硬币组成 j-coins[i-1] 的方案数，即刚好差一个当前硬币的金额
就是用和不用的区别，不用的话就是 dp[i-1][j]，用的话就是 dp[i][j-coins[i-1]]，这样就不会重复计算了

递推：
int dp[amount + 1][n+1];
memset(dp, 0, sizeof(dp))
dp[0][0] = 1;
for (int i = 0; i < coins.size(); i++) {
    for (int j = 0; j <= amount; j++) {
        dp[i+1][j] = dp[i][j] + (j >= coins[i] ? dp[i+1][j-coins[i]] : 0);
    }
}

所以其实是个完全背包问题，选还是不选
也即外层遍历应该是物品/硬币，内层遍历是背包/金额
同时发现 dp[i+1][j] 只和 dp[i][j] 和 dp[i+1][j-coins[i]] 有关，所以可以优化成一维数组
dp[j] = dp[j] + dp[j-coins[i]]，同时内层循环从 coins[i] 开始遍历

实际上，DP 最好从多个状态开始想，也即二维 DP 开始慢慢降维，而不是一开始就降维
*/

class Solution {
 public:
  int change(int amount, vector<int>& coins) {
    int n = coins.size();
    int dp[amount + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int x : coins) {
      for (int j = x; j <= amount; j++) {
        dp[j] += dp[j - x];
      }
    }
    return dp[amount];
  }
};

class Test {
 public:
  int change(int amount, vector<int>& coins) {
    int n = coins.size();
    int dp[n + 1][amount + 1];

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int j = 0; j <= amount; j++) {
      for (int i = 0; i < n; i++) {
        dp[i + 1][j] = dp[i][j] + (j >= coins[i] ? dp[i + 1][j - coins[i]] : 0);
      }
    }

    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= amount; j++) {
        cout << dp[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
    return dp[n][amount];
  }
};

int main() {
  Solution solution;
  Test test;
  vector<int> coins = {1, 2, 5};
  cout << test.change(5, coins) << endl;
  cout << solution.change(5, coins) << endl;
  return 0;
}