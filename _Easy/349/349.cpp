#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must be unique and you may return the result in any order.

方法一：哈希表
用两个哈希表统计 nums1 中的数字
然后遍历 nums2 如果在 nums1 中出现过，就加入结果集，同时 mp[num] = 0 防止重复
时间复杂度 O(max(n,m))
空间复杂度 O(max(n,m))

方法二：排序 + 双指针

时间复杂度 O(nlogn + mlogm)
空间复杂度 O(logn + logm) 排序的空间复杂度

 */
class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    unordered_map<int, int> mp;
    for (const auto& num : nums1) {
      mp[num]++;
    }
    for (const auto& num : nums2) {
      if (mp[num]) {
        ans.emplace_back(num);
        mp[num] = 0;  // deduplicate
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}
