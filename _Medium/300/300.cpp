
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。

例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
示例 2：

输入：nums = [0,1,0,3,2,3]
输出：4
示例 3：

输入：nums = [7,7,7,7,7,7,7]
输出：1


方法一：DP
假设 dp[i] 是以 nums[i] 结尾的最长上升子序列
for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
            dp[i] = max(dp[i], dp[j] + 1)
            ans = max(ans, dp[i]);
        }
    }
}

方法二：DP + 二分 + 贪心

此时 dp[:] 是有序的，
如果 dp[len] < nums[i]，则更新 dp[++len] （len 初始化为 1）
否则在 dp[1...len] 中找到一个 dp[i - 1] < nums[j] < dp[i]
 */
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
      return 0;
    }
    vector<int> dp(n + 1);
    int len = 1;
    dp[len] = nums[0];
    for (int i = 1; i < n; i++) {
      if (nums[i] > dp[len]) {
        dp[++len] = nums[i];
      } else {
        /* 二分找到第一个小于 nums[i] 的数 dp[k]  */
        int l = 1, r = len;
        int pos = 0;
        while (l <= r) {
          int m = l + (r - l) / 2;
          if (dp[m] < nums[i]) {
            pos = m;
            l = m + 1;
          } else {
            r = m - 1;
          }
        }
        dp[pos + 1] = nums[i];
      }
    }
    return len;
  }
};

int main() {

  Solution test;
  return 0;
}