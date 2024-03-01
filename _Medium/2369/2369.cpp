
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个下标从 0 开始的整数数组 nums ，你必须将数组划分为一个或多个 连续 子数组。

如果获得的这些子数组中每个都能满足下述条件 之一 ，则可以称其为数组的一种 有效 划分：

子数组 恰 由 2 个相等元素组成，例如，子数组 [2,2] 。
子数组 恰 由 3 个相等元素组成，例如，子数组 [4,4,4] 。
子数组 恰 由 3 个连续递增元素组成，并且相邻元素之间的差值为 1 。例如，子数组 [3,4,5] ，但是子数组 [1,3,5] 不符合要求。
如果数组 至少 存在一种有效划分，返回 true ，否则，返回 false 。

2 <= nums.length <= 1e5

输入：nums = [4,4,4,5,6]
输出：true
解释：数组可以划分成子数组 [4,4] 和 [4,5,6] 。
这是一种有效划分，所以返回 true 。

方法一：动态规划
为什么是动态规划？
首先找到状态：
如果 nums 最后两个数相同，则去掉这两个数，问题变成 nums[:n-2] 是否可以划分。
如果 nums 最后三个数相同，则去掉这三个数，问题变成 nums[:n-3] 是否可以划分。
如果 nums 最后三个数连续递增，则去掉这三个数，问题变成 nums[:n-3] 是否可以划分。
所以状态是：dp[i+1] 表示 nums[:i] 是否可以划分。
因为 dp[i+1] - dp[i-1] 表示 nums[:i] 到 nums[:i-2] 中间隔了两个数

dp[i+1] = true, if dp[i-1] && (nums[i] == nums[i - 1])
dp[i+1] = true, if dp[i-2] if (nums[i] == nums[i - 1] && nums[i] == nums[i - 2])
dp[i+1] = true, if dp[i-2] if (nums[i] == nums[i - 1] + 1 && nums[i - 1] == nums[i - 2] + 1)

最后返回 dp[n] 表示 nums[:n-1]  
 */

class Solution {
 public:
  bool validPartition(vector<int>& nums) {
    int n = nums.size();
    vector<bool> dp(n + 1);
    dp[0] = true;

    // dp[i] 表示 nums[:i-1]
    for (int i = 1; i <= n; i++) {
      dp[i] = dp[i] || (i >= 2 && (nums[i - 1] == nums[i - 2]) && dp[i - 2]);
      dp[i] = dp[i] || (i >= 3 && (nums[i - 1] == nums[i - 2]) && (nums[i - 2] == nums[i - 3]) && dp[i - 3]);
      dp[i] = dp[i] || (i >= 3 && (nums[i - 1] == nums[i - 2] + 1) && (nums[i - 2] == nums[i - 3] + 1) && dp[i - 3]);
    }

    return dp[n + 1];
  }
};

int main() {

  Solution test;
  return 0;
}