#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
713. 乘积小于 K 的子数组

Given an array of integers nums and an integer k, 
return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

Input: nums = [1,2,3], k = 0
Output: 0

方法一：滑动窗口
连续子数组 乘积小于 k
暴力：枚举所有子数组，时间复杂度 O(n^2)
在枚举所有连续子数组的过程中可以发现，如果 nums[i] * nums[i+1] * ... * nums[j] > k
第一个去掉的是 nums[i]，然后是 nums[i+1]，直到 nums[j]
考虑滑动窗口，每次右指针右移，如果乘积大于 k，左指针右移
如果此时 nums[i] * nums[i+1] * ... * nums[j] < k
一共有 [i, j], [i+1, j], ..., [j, j] 这 j-i+1 个子数组
时间复杂度 O(n)

问题：为什么不是动态规划？
1. 连续子数组，不是子序列
 */
class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int n = nums.size();
    int l = 0, curMul = 1;
    int ans = 0;
    for (int r = 0; r < n; r++) {
      curMul *= nums[r];
      while (curMul >= k) {
        curMul /= nums[l++];
      }
      ans += r - l + 1;  // 一共 r - l + 1 个子数组
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}
