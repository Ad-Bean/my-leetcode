/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
 *
 *
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 * 
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
 * 
 * 
 * 输入: [3,2,1,5,6,4], k = 2
 * 输出: 5
 * 
 * 
 * 输入: [3,2,3,1,2,4,5,5,6], k = 4
 * 输出: 4
 * 
 * 
 * 1 <= k <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 * 方法一：排序 Ologn
 * 排序后返回 nums[n - k]
 * 
 * 方法二：堆排序 Ologn
 * 每次取出最大的元素，取 k 次
 * 
 * 方法三：快速选择 On
 * 随机选择一个 pivot，将数组分为两部分 a[l:i] a[j:r] 
 * 前者每个元素小于等于 pivot 后者每个元素大于 pivot
 * 如果此时 n - k <= j，由于 n - k 表示第 k 大（升序数组的下标），表示第 k 大在前面部分，
 * 继续递归解决 quickSelect(nums, l, j, n - k)
 * 否则在后部分，quickSelect(nums, j + 1, r, n - k)
 * 
 * 细节：
 * pivot 直接选择 l，随机不知道为什么会出错
 * i 和 j 的初始值为 l - 1 和 r + 1，且 while 先 --j 和 ++i
 * 是为了防止 nums 中有相等的元素，最终导致 i != j 死循环
 * 
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
// @lc code=start
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    function<int(int, int)> quickSelect = [&](int l, int r) {
      if (l == r) {
        return nums[n - k];
      }
      int pivot = l;
      int i = l - 1, j = r + 1;
      while (i < j) {
        while (nums[pivot] < nums[--j]) {}
        while (nums[pivot] > nums[++i]) {}
        if (i < j) {
          swap(nums[i], nums[j]);
        }
      }
      if (n - k <= j) {
        return quickSelect(l, j);  // n - k 第 k 大在前面
      } else {
        return quickSelect(j + 1, r);
      }
    };
    return quickSelect(0, n - 1);
  }
};
// @lc code=end

int main() {
  Solution test;
  // vector<int> nums = {3, 2, 1, 5, 6, 4};
  // cout << test.findKthLargest(nums, 2) << endl;
  vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  cout << test.findKthLargest(nums2, 4) << endl;
}