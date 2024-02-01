/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 *
 * https://leetcode.cn/problems/minimum-size-subarray-sum/description/
 *
 * 给定一个含有 n 个正整数的数组和一个正整数 target 。
 * 
 * 找出该数组中满足其总和大于等于 target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr]
 * ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
 * 
 * 
 * 输入：target = 7, nums = [2,3,1,2,4,3]
 * 输出：2
 * 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
 * 
 * 
 * 输入：target = 4, nums = [1,4,4]
 * 输出：1
 * 
 * 
 * 输入：target = 11, nums = [1,1,1,1,1,1,1,1]
 * 输出：0
 * 
 * 
 * 
 * 1 <= target <= 10^9
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 * 
 * 进阶：
 * 
 * 
 * 如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。
 * 
 * 方法一：暴力 O(n^2) 超时
    int len = 0x3f3f3f3f;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (nums[i] >= target) {
        return 1;
      }

      int sum = nums[i];
      for (int j = i + 1; j < n; j++) {
        if (sum + nums[j] >= target) {
          len = min(len, j - i + 1);
          break;
        }
        sum += nums[j];
      }
    }
    return len == 0x3f3f3f3f ? 0 : len;
 *  
 * 
 * 方法二：前缀和
 * 对于数组的某一段连续子数组的和，最快的是用前缀和查询
 * 同时由于所有元素都是正数，前缀和是递增的
 * 如何查询 pre[r] - pre[l] >= target 呢？
 * 由于 pre[r] 是 sum(nums[:r]) 往前找一个值 x，使得 pre[r] - x >= target
 * 为了使得 r - l 尽可能小，也就是说 x 的位置越靠后，就是找一个最大的 x 值
 * 即找一个大于等于 x == pre[r] - target 然后往后挪一位
 * 
 * 比如 nums = [2,3,1,2,4,3] target = 7
 *      pre = [0,2,5,6,8,12,15]
 * 
 * 对于 pre[0] 跳过
 * 对于 pre[1] = 2 找一个大于 -6
 * 对于 pre[2] = 5 找一个大于 -2
 * 对于 pre[4] = 8  找一个大于 8 -7=1 后一位即 l=0, 4-0 = 4 长度 4 
 * 对于 pre[5] = 12 找一个大于 12-7=5 后一位即 l=2, 5-2 = 3 长度 3
 * 对于 pre[6] = 15 找一个大于 15-7=8 后一位即 l=4, 6-4 = 2 长度 2
 * 
 * 7
 * [1,1,1,1,7]
 * 
 * pre: [0, 1, 2, 3, 4, 11]
 * 
 * 对于 pre[5] = 11 找一个大于 11-7=8 后一位即 l =4, 5-4 长度 1
 * 
 * 
 * 方法三：双指针 On
 * 记录 sum = 0
 * 遍历 nums[r] 并且 sum += nums[r]
 * 一旦 sum >= t 就缩短这个子数组 
 * 
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class SolutionPre {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int len = 0x3f3f3f3f;
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
      pre[i] = pre[i - 1] + nums[i - 1];
      //   cout << pre[i] << " ";
    }
    // cout << endl;

    for (int r = 1; r <= n; r++) {
      int x = pre[r] - target;
      if (x < 0) {
        continue;
      }

      auto l = upper_bound(pre.begin(), pre.end(), x) - pre.begin();
      //   cout << "find: " << x << " " << l << " " << r << " " << pre[r] << " - " << pre[l] << endl;
      len = min(len, int(r - l + 1));
    }
    return len == 0x3f3f3f3f ? 0 : len;
  }
};

// @lc code=start
class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int len = n + 1;
    int l = 0, sum = 0;
    for (int r = 0; r < n; r++) {
      sum += nums[r];
      while (sum >= target) {
        len = min(len, r - l + 1);
        sum -= nums[l++];
      }
    }
    return len == n + 1 ? 0 : len;
  }
};
// @lc code=end

int main() {
  Solution test;
  vector<int> t = {1, 1, 1, 1, 7};
  int tar = 7;
  cout << test.minSubArrayLen(tar, t) << endl;
}
