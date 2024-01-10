#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个下标从 0 开始的整数数组 nums 。

如果一个前缀 nums[0..i] 满足对于 1 <= j <= i 的所有元素都有 nums[j] = nums[j - 1] + 1 ，
那么我们称这个前缀是一个 顺序前缀 。特殊情况是，只包含 nums[0] 的前缀也是一个 顺序前缀 。

请你返回 nums 中没有出现过的 最小 整数 x ，满足 x 大于等于 最长 顺序前缀的和。

方法一：集合/哈希
1. 求最长连续递增前缀元素和 sum
2. set / map
3. 遍历 set， while sum in st: sum += 1  O(n) 
 */
class Solution {
 public:
  int missingInteger(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, bool> mp;
    int sum = nums[0];
    mp[nums[0]] = true;
    bool flag = true;
    for (int i = 1; i < n; i++) {
      if (nums[i] != nums[i - 1] + 1) {
        flag = false;
      }
      if (flag) {
        sum += nums[i];
      }
      mp[nums[i]] = true;
    }
    for (int i = sum; i < 2501; i++) {
      if (mp[i]) {
        continue;
      }
      return i;
    }
    return -1;
  }
};
int main() {
  vector<int> nums = {4, 5, 6, 7, 8, 8, 9, 4, 3, 2, 7};
  Solution test;
  cout << test.missingInteger(nums) << endl;
  return 0;
}