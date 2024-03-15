#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

/* 
Given an integer array nums, return an array answer such that 
answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

方法一：
暴力：将所有数相乘，然后除以 nums[i] 得到答案，但很明显会被 0 限制
优化：用两个数组记录前缀积和后缀积，然后相乘得到答案

数组   1,2,3,4
前缀积 1,2,6,24
从后向前遍历，后缀积 1,4,12,24

优化：直接使用 ans 答案数组记录前缀积，然后用 suf 记录后缀积
空间复杂度 O(1)

 */
class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    ans[0] = nums[0];
    for (int i = 1; i < n; i++) {
      ans[i] = ans[i - 1] * nums[i];
    }
    int suf = 1;
    for (int i = n - 1; i > 0; i--) {
      ans[i] = ans[i - 1] * suf;
      suf = suf * nums[i];
    }
    ans[0] = suf;
    return ans;
  }
};
int main() {

  Solution test;
  vector<int> nums = {1, 2, 3, 4};
  vector<int> ans = test.productExceptSelf(nums);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  vector<int> nums2 = {-1, 1, 0, -3, 3};
  vector<int> ans2 = test.productExceptSelf(nums2);
  for (int i = 0; i < ans2.size(); i++) {
    cout << ans2[i] << " ";
  }
  return 0;
}
