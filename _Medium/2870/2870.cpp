
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个下标从 0 开始的正整数数组 nums 。

你可以对数组执行以下两种操作 任意次 ：

从数组中选择 两个 值 相等 的元素，并将它们从数组中 删除 。
从数组中选择 三个 值 相等 的元素，并将它们从数组中 删除 。
请你返回使数组为空的 最少 操作次数，如果无法达成，请返回 -1 。

输入：nums = [2,3,3,2,2,4,2,3,4]
输出：4
解释：我们可以执行以下操作使数组为空：
- 对下标为 0 和 3 的元素执行第一种操作，得到 nums = [3,3,2,4,2,3,4] 。
- 对下标为 2 和 4 的元素执行第一种操作，得到 nums = [3,3,4,3,4] 。
- 对下标为 0 ，1 和 3 的元素执行第二种操作，得到 nums = [4,4] 。
- 对下标为 0 和 1 的元素执行第一种操作，得到 nums = [] 。
至少需要 4 步操作使数组为空。


方法一：贪心
哈希计数
如果是 3 的倍数，cnt/3 删除
如果不是 3 的倍数
cnt % 3 == 1, (cnt-4)/3 + 2
cnt % 3 == 2, (cnt-2)/3 + 1
 */
class Solution {
 public:
  int minOperations(vector<int>& nums) {
    unordered_map<int, int> cnt;
    for (const int& num : nums) {
      cnt[num]++;
    }
    int ans = 0;
    for (const auto& [k, v] : cnt) {
      if (v == 1) {
        return -1;
      }
      if (v % 3 == 0) {
        ans += v / 3;
      } else if (v % 3 == 1) {
        ans += (v - 4) / 3 + 2;
      } else {
        ans += (v - 2) / 3 + 1;
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}