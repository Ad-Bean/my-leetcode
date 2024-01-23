/*
 * @lc app=leetcode.cn id=2765 lang=cpp
 *
 * [2765] 最长交替子数组
 */
/* 
给你一个下标从 0 开始的整数数组 nums 。
如果 nums 中长度为 m 的子数组 s 满足以下条件，我们称它是一个 交替子数组 ：

m 大于 1 。
s1 = s0 + 1 。
下标从 0 开始的子数组 s 与数组 [s0, s1, s0, s1,...,s(m-1) % 2] 一样。
也就是说，s1 - s0 = 1 ，s2 - s1 = -1 ，s3 - s2 = 1 ，s4 - s3 = -1 
，以此类推，直到 s[m - 1] - s[m - 2] = (-1)^m 。
请你返回 nums 中所有 交替 子数组中，最长的长度，如果不存在交替子数组，请你返回 -1 。

子数组是一个数组中一段连续 非空 的元素序列。

输入：nums = [2,3,4,3,4]
输出：4
解释：交替子数组有 [3,4] ，[3,4,3] 和 [3,4,3,4] 。
最长的子数组为 [3,4,3,4] ，长度为4 。

方法一：遍历 On^2
从 i 到 j 的连续子数组，检查 nums[j] - nums[i] 相等还是差 1: (m - 1)%2

方法二：动态规划 On On
dp[i] 表示以 i 结尾的最长交替子数组
dp[0] = 1
如果 dp[i - 1] == 1, dp[i] = (nums[i] == nums[i -1]) + 1 // 要变成偶数长度
如果 dp[i - 1] >  1,
  如果 nums[i] == nums[i - 2] 则 dp[i] = dp[i - 1] + 1
  否则无法交替，dp[i] = (nums[i] == nums[i -1]) + 1
最后返回 dp 中最大的，否则是 -1

int n = nums.size();
vector<int> dp(n, 1);
for (int i = 1; i < n; i++) {
  if (dp[i - 1] == 1) {                          // 子数组长度等于一
    dp[i] = 1 + (nums[i] == nums[i - 1] + 1);    // 和前个相差 1
  } else {                                       // 子数组长度大于一
    if (nums[i] == nums[i - 2]) {                // 和前前个相等
      dp[i] = dp[i - 1] + 1;                     //
    } else {                                     // 和前前个不等
      dp[i] = 1 + (nums[i] == nums[i - 1] + 1);  // 是否差一
    }
  }
}
int ans = *max_element(dp.begin(), dp.end());
return ans == 1 ? -1 : ans;

方法三：分组循环 On O1
数组会被分割成若干组，且每一组的判断/处理逻辑是一样的
int ans = -1;
int i = 0, n = nums.size();
while (i < n - 1) {
    if (nums[i + 1] - nums[i] != 1) {
        i++; // 直接跳过
        continue;
    }
    int i0 = i; // 记录这一组的开始位置
    i += 2; // i 和 i+1 已经满足要求，从 i+2 开始判断
    while (i < n && nums[i] == nums[i0] + (i - i0) % 2) {
        i++;
    }
    ans = max(ans, i - i0); // 从 i0 到 i-1 是满足题目要求的（并且无法再延长的）子数组
    i--;
}
return ans;

 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

// @lc code=start
class Solution {
 public:
  int alternatingSubarray(vector<int>& nums) {
    int ans = -1;
    int i = 0, n = nums.size();
    while (i < n - 1) {
      if (nums[i + 1] - nums[i] != 1) {
        i++;  // 直接跳过
        continue;
      }
      int i0 = i;  // 记录这一组的开始位置
      i += 2;      // i 和 i+1 已经满足要求，从 i+2 开始判断
      while (i < n && nums[i] == nums[i0] + (i - i0) % 2) {
        i++;
      }
      ans = max(ans, i - i0);  // 从 i0 到 i-1 是满足题目要求的（并且无法再延长的）子数组
      i--;
    }
    return ans;
  }
};
// @lc code=end

int main() {

  Solution test;
  vector<int> t = {21, 9, 5};
  cout << test.alternatingSubarray(t) << endl;
  return 0;
}