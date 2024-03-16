#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
Given a binary array nums, 
return the maximum length of a contiguous subarray with an equal number of 0 and 1.

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
 
Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

方法一：前缀和 + 哈希表
什么情况下子数组 0 和 1 数量相等
区间长度 r - l + 1 是偶数且区间和为 (r - l + 1) / 2 

所以可以尝试前缀和，但是再转换一下题意
可以将 0 变成 -1，然后求和为 0 的最长子数组，就不需要滑动窗口
只需要前缀和 + 哈希表判断上一次

一定要记住初始化 mp[0] = 0; 或者 从 0 开始遍历

优化：不需要前缀和数组，直接用一个变量记录即可，并且一边遍历一边更新哈希表
从 i = 0 开始遍历一定要注意下标
如果 mp[pre] 存在，说明之前有一个位置的前缀和是 pre，那么这个位置到现在的位置的子数组和为 0
i - mp[pre] + 1
否则，更新 mp[pre] = i + 1 // 推后一位，预留 0 的位置
注意，mp 存下标，存在 0 不能用 mp[0] 来判断，要用 mp.count(0)
 */
class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    int n = nums.size();
    int pre = 0;
    int ans = 0;
    unordered_map<int, int> mp;
    mp[0] = 0;
    for (int i = 0; i < n; i++) {
      pre += (nums[i] == 0 ? -1 : 1);
      if (mp.count(pre)) {
        ans = max(ans, i - mp[pre] + 1);
      } else {
        mp[pre] = i + 1;
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  //   vector<int> nums = {
  //       0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
  //   };
  //   cout << test.findMaxLength(nums) << endl;
  vector<int> nums2 = {0, 1};
  cout << test.findMaxLength(nums2) << endl;
  return 0;
}
