#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。

输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

1 <= nums.length <= 10^5

方法一：动态规划
最大和的连续子数组
暴力：两层遍历找到一个区间 [i, j] 的和，用前缀和求，时间复杂度 O(n^2) 无法通过
可以发现对 nums[i] 有一个状态，它可以是前面的和加上自己，也可以是自己，所以可以用动态规划
设 dp[i] 表示到 i 位置的连续子数组最大和
dp[i] = max(dp[i - 1] + nums[i], nums[i])
但是 dp[n] 并不是答案，而是 max(dp[:])

int n = nums.size();
vector<int> dp(n);
dp[0] = nums[0];
int ans = nums[0];
for (int i = 1; i < n; i++) {
  dp[i] = max(dp[i - 1] + nums[i], nums[i]);
  ans = max(ans, dp[i]);
}
return max(ans, dp[n - 1]);

是因为状态是 dp[i] 是以 nums[i] 结尾的最大连续和


滚动数组优化：
发现 dp[i] 只和 dp[i - 1] 有关，只用一个变量表示 dp[i] 即可


方法二：分治 / 线段树 push up
get(a, l, r) 表示查询 a 序列 [l,r] 区间内的最大子段和

get(nums, 0, nums.size() - 1)

对于一个区间 [l,r]，我们取 m=⌊l+r2⌋，对区间 [l,m] 和 [m+1,r] 分治求解

Status pushUp(Status l, Status r) {
    int iSum = l.iSum + r.iSum;
    int lSum = max(l.lSum, l.iSum + r.lSum);
    int rSum = max(r.rSum, r.iSum + l.rSum);
    int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
    return (Status) {lSum, rSum, mSum, iSum};
};

struct Status {
    int 
    lSum,     // 以 l 为左端点的最大子段和
    rSum,     // 以 r 为右端点的最大子段和
    mSum,     // l,r 内的最大子段和
    iSum;     // l,r 区间和
};

 */
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int pre = nums[0];
    int ans = nums[0];
    for (int i = 1; i < n; i++) {
      pre = max(pre + nums[i], nums[i]);
      ans = max(ans, pre);
    }
    return ans;
  }
};

int main() {

  Solution test;
  return 0;
}