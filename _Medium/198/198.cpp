#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
你是一个专业的小偷，计划偷窃沿街的房屋。
每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，
一夜之内能够偷窃到的最高金额。

 
输入：[1,2,3,1]
输出：4

方法一：动态规划
dp[i] 表示前 i 个房屋能偷窃到的最高金额
dp[i] = max(dp[i-2] + nums[i-1], dp[i-1])

优化：滚动数组
dp[i] 只和 dp[i-1] 和 dp[i-2] 有关

 */

class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {
      return nums[0];
    }
    // vector<int> dp(n + 1);
    // dp[1] = nums[0];
    // for (int i = 2; i <= n; i++) {
    //   dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
    // }
    // return dp[n];
    int fir = nums[0], sec = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
      int t = sec;
      sec = max(fir + nums[i], sec);
      fir = t;
    }
    return sec;
  }
};
int main() {

  Solution test;
  return 0;
}