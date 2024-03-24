#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

/* 
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

Input: nums = [1,3,4,2,2]
Output: 2

由于一共有 n + 1 个数，且范围一定在 [1, n]
只有一个重复的数，找出重复的

方法一：哈希表 O(n) O(n)
遍历一遍原数组，记录每个数出现次数，一旦 mp[nums[i]] > 1 就返回

方法二：快慢指针 O(n) O(1)
题目要求空间复杂度 O(1)
考虑如何在链表中判断是否成环（快慢指针、Floyd 判圈）
对原数组建图， i -> nums[i] 建边，由于一定有重复数字，则一定有两条边指向同一个数字
比如 [1, 3, 4, 2, 2]，建图为 1 -> 3 -> 2 -> 4 -> 2 此时 2 为环入口 也就是重复的数字
快慢指针 l 和 r，如果有环则一定会相遇
l = nums[l], r = nums[nums[r]]，直到 l == r
最后判断环的入口即重复数字
此时慢指针走了 comm + k 步
快指针走了 comm + k + n * loop 步 同时也是慢指针的两倍也是 2 * comm + 2 * k 步
有公式 comm + k + n * loop = 2 * comm + 2 * k
即 comm = n * loop - k = (n - 1) * loop + (loop - k) = (n - 1) * loop + C
此时让慢指针从头再开始走，快指针从相遇点开始走
最终他们会在环入口相遇，因为慢指针走了 comm 而快指针走了 C
注意最后返回 l 或 r 而不是 nums[l]

这种做法的前提是 nums[i] 一定在 [1, n] 之间

方法三：二分查找 O(nlogn) O(1)
由于空间复杂度需要为 O(1)
所以尝试将哈希表的方法改进
由于 cnt[nums[i]] 具有单调性，只有重复的数满足 cnt[nums[i]] == 2，其他都是 1
二分范围：[1, n]
每次 mid = (l + r) / 2，统计 nums 中小于等于 mid 的数的个数 cnt
如果 cnt > mid 说明重复的数在 [1, mid] 之间
如果 cnt <= mid 说明重复的数在 [mid + 1, n] 之间
 */
class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    int l = 0, r = 0;
    do {
      l = nums[l];
      r = nums[nums[r]];
    } while (l != r);
    l = 0;
    while (l != r) {
      l = nums[l];
      r = nums[r];
    }
    return l;
  }
};
int main() {

  Solution test;
  return 0;
}
