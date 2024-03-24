#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

你可以认为每种硬币的数量是无限的。

输入：coins = [1, 2, 5], amount = 11
输出：3 
解释：11 = 5 + 5 + 1

方法一：动态规划
贪心来看，为了选出硬币数量最少的方案
先选面额最大的
sort(coins.begin(), coins.end(), greater<int>());  // 注意在堆中 greater<int>() 为最小堆，因为堆后面的元素要大于堆顶
然后从大到小遍历每次取出 amount /= coins[i] 直到 amount = 0

但是这样会存在一些问题，不知道停止条件

所以使用动态规划
dp[i] 表示 amount == i 时硬币数量最少的方案
dp[i] = min(dp[i], dp[i - coins[j]] + 1) 所以需要前面的状态
比如 
dp[1] = min(dp[1-1] + 1, dp[1-2] + 1, dp[1-5] + 1) = 1
dp[2] = min(dp[2-1] + 1, dp[2-2] + 1, dp[2-5] + 1) = 1
...
以此类推

方法二：记忆化搜索
*/

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) {
      return 0;
    }
    int n = coins.size();
    vector<int> dp(amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
      dp[i] = 0x3f3f3f3f;
      for (int j = 0; j < n; j++) {
        if (i >= coins[j]) {
          dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
      }
    }
    return dp[amount] == 0x3f3f3f3f ? -1 : dp[amount];
  }
};
int main() {

  Solution test;
  return 0;
}
