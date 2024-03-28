#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

方法一：排序 + 双指针
时间复杂度 O(nlogn)
空间复杂度 O(1)

有序数组可以直接用双指针解决
考虑三数之和

方法二：哈希表
时间复杂度 O(n)
空间复杂度 O(n)

哈希表记录每个数的下标，目标找到 target - x 的下标

 */
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++) {
      if (hash.count(target - nums[i])) {
        return {hash[target - nums[i]], i};
      }
      hash[nums[i]] = i;
    }
    return {};
  }
};
int main() {

  Solution test;
  return 0;
}