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
 * 
 * 方法二：堆排序 Ologn
 * 
 * 方法三：快排 On
 * 分治：先分解 a[l:r] 成两部分 a[l:q-1] a[q+1:r] 前者全部小于 a[q] 后者全部大于
 * 递归：继续分解
 * 合并：使 a[l..r] 有序
 * 
 * 只要某次划分的 q 为 倒数第 k 个下标 的时候，就是第 k 大
 * 
 * 分解时：如果 a[q] 比目标小
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
// @lc code=start
class Solution {
  int quickselect(vector<int>& nums, int k) {
    int pivot = nums[rand() % nums.size()];
    vector<int> l, m, r;
    for (const int num : nums) {
      if (num < pivot) {
        l.emplace_back(num);
      } else if (num > pivot) {
        r.emplace_back(num);
      } else {
        m.emplace_back(num);
      }
    }
    // kth largest in the r
    if (k <= r.size()) {
      return quickselect(r, k);
    }
    // kth largest in l, recursive
    if (k > m.size() + r.size()) {
      return quickselect(l, k - (r.size() + m.size()));
    }
    // kth largest in m, return pivot
    return pivot;
  }

 public:
  int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    srand(time(NULL));
    return quickselect(nums, k);
  }
};
// @lc code=end
