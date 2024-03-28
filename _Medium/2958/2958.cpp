#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个整数数组 nums 和一个整数 k 。
一个元素 x 在数组中的 频率 指的是它在数组中的出现次数。
如果一个数组中所有元素的频率都 小于等于 k ，那么我们称这个数组是 好 数组。

请你返回 nums 中 最长 好子数组的长度。

子数组 指的是一个数组中一段连续非空的元素序列。
输入：nums = [1,2,3,1,2,3,1,2], k = 2
输出：6
解释：最长好子数组是 [1,2,3,1,2,3] ，值 1 ，2 和 3 在子数组中的频率都没有超过 k = 2 。[2,3,1,2,3,1] 和 [3,1,2,3,1,2] 也是好子数组。
最长好子数组的长度为 6 。

方法一：滑动窗口
连续子数组 频率小于等于 k
考虑滑动窗口，经典做法
和 713. 乘积小于 K 的子数组 一样

 */
class Solution {
 public:
  int maxSubarrayLength(vector<int>& nums, int k) {
    int n = nums.size();
    int l = 0, ans = 0;
    unordered_map<int, int> freq;
    for (int r = 0; r < n; r++) {
      freq[nums[r]]++;
      while (freq[nums[r]] > k) {
        freq[nums[l++]]--;
      }
      ans = max(ans, r - l + 1);
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}
