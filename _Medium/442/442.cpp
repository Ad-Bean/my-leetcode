#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个长度为 n 的整数数组 nums ，其中 nums 的所有整数都在范围 [1, n] 内，且每个整数出现 一次 或 两次 。
请你找出所有出现 两次 的整数，并以数组形式返回。

你必须设计并实现一个时间复杂度为 O(n) 且仅使用常量额外空间的算法解决此问题

输入：nums = [4,3,2,7,8,2,3,1]
输出：[2,3]

1 <= nums[i] <= n
nums 中的每个元素出现 一次 或 两次

方法一：哈希 
由于元素范围 [1,n] 且有许多元素出现两次，无法使用 287 中的快慢指针
考虑使用哈希，但是题目要求常量额外空间
于是尝试原地哈希，将每个元素放到正确的位置上
对 nums[i] 应该放到 nums[i] - 1 下标上，如果重复，则维护一个从左到右的空位，将重复元素放到空位上

最后，对数组遍历，如果 nums[i] != i + 1 则表示 i + 1 是重复元素
for (int i = 0; i < n; i++) {
    while (nums[i] != nums[nums[i] - 1]) {
        swap(nums[i], nums[nums[i] - 1]);
    }
}

交换次数是 O(n)，所以时间复杂度是 O(n)
所有操作都是原地的，所以空间复杂度是 O(1)
只有重复出现的数字，不会进行 swap，因为此时 nums[i] == nums[nums[i] - 1]

方法二：正负标记
由于是为了找到出现两次的，剩下全是一次
将所有出现一次的数字标记为负数，如果已经是负数了，说明是重复的
但是为了常量空间
用原数组的正负号来标记是否出现过
for (int i = 0; i < n; i++) {
    int x = abs(nums[i]);
    if (nums[x - 1] > 0) {
        nums[x - 1] = -nums[x - 1];  // 标记 x 出现过
    } else { 
        ans.emplace_back(x);         // 表示 x 已经出现过
    }
}

*/
class Solution {
 public:
  vector<int> findDuplicates(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      while (nums[i] != nums[nums[i] - 1]) {
        swap(nums[i], nums[nums[i] - 1]);
      }
    }
    for (int i = 0; i < n; i++) {
      if (nums[i] != i + 1) {
        ans.emplace_back(nums[i]);
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}
