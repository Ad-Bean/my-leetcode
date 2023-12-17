
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。
一旦你支付此费用，即可选择向上爬一个或者两个台阶。

你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。

请你计算并返回达到楼梯顶部的最低花费。


输入：cost = [10,15,20]
输出：15
解释：你将从下标为 1 的台阶开始。
- 支付 15 ，向上爬两个台阶，到达楼梯顶部。
总花费为 15 。

dp[0] = 10
dp[1] = 15
dp[2] = min(15, 10) + 20 = 20+ 10 = 30

return min(dp[n-1], dp[n-2])

输入：cost = [1,100,1,1,1,100,1,1,100,1]
输出：6
解释：你将从下标为 0 的台阶开始。
- 支付 1 ，向上爬两个台阶，到达下标为 2 的台阶。
- 支付 1 ，向上爬两个台阶，到达下标为 4 的台阶。
- 支付 1 ，向上爬两个台阶，到达下标为 6 的台阶。
- 支付 1 ，向上爬一个台阶，到达下标为 7 的台阶。
- 支付 1 ，向上爬两个台阶，到达下标为 9 的台阶。
- 支付 1 ，向上爬一个台阶，到达楼梯顶部。
总花费为 6 。

方法一：动态规划
dp[i] 表示到下标 i 的最小花费
dp[i] = min(dp[i-1], dp[i-2]) + cost[i]

滚动数组：
int f0 = cost[0];
int f1 = cost[1];
for (int i = 2; i < n; i++) {
    int f2 = min(f0, f1) + cost[i];
    f0 = f1;
    f1 = f2;
}

 */
class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    int f0 = cost[0];
    int f1 = cost[1];
    for (int i = 2; i < n; i++) {
      int f2 = min(f0, f1) + cost[i];
      f0 = f1;
      f1 = f2;
    }
    return min(f0, f1);
  }
};
int main() {

  Solution test;
  return 0;
}