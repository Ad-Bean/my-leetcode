#include <bits/stdc++.h>
using namespace std;
/* 
给你一个下标从 0 开始的整数数组 nums 和一个整数 k 。

一开始你在下标 0 处。每一步，你最多可以往前跳 k 步，但你不能跳出数组的边界。
也就是说，你可以从下标 i 跳到 [i + 1， min(n - 1, i + k)] 包含 两个端点的任意位置。

你的目标是到达数组最后一个位置（下标为 n - 1 ），你的 得分 为经过的所有数字之和。

请你返回你能得到的 最大得分 。


方法一：动态规划
子问题：0,n-1 分解  [n-1-k, n-1] [[n-k, n-1]] ...
从后往前 dfs(n-1)
function<int(int)> dfs = [&](int i) -> int {
    if (i == 0) {
        return nums[0];
    }
    int mx = INT_MIN;
    for (int j = max(i - k, 0); j < i; j++) {
        mx = max(mx, dfs(j));
    }
    return mx + nums[i];
};

递推：dp[i] = dp[j]+nums[i] for j in max(i-k,0)
int maxResult(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> f(n);
    f[0] = nums[0];
    for (int i = 1; i < n; i++) {
        f[i] = *max_element(f.begin() + max(i - k, 0), f.begin() + i) + nums[i];
    }
    return f[n - 1];
}
但是 O(nk) 会超时，需要单调队列优化
i <  k 时，取 f[:i-1] 的最大值
i >= k 时，取 f[i-k:i-1] 最大值
即长度为 k 的滑动窗口最大值，可以用单调队列
维护一个 f 值从左到右严格递减的单调队列（双端队列），在计算 f[i] 时，需要保证队首就是转移来源最大值的下标

 */
typedef long long ll;
typedef pair<int, int> pii;
class Solution {
 public:
  int maxResult(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    deque<int> q;
    q.push_back(0);
    for (int i = 1; i < n; i++) {
      if (q.front() < i - k) {
        q.pop_front();
      }
      dp[i] = dp[q.front()] + nums[i];
      while (!q.empty() && dp[i] >= dp[q.back()]) {
        q.pop_back();
      }
      q.push_back(i);
    }
    return dp[n - 1];
  }
};
int main() {

  Solution test;
  return 0;
}
