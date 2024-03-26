
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个未排序的整数数组 nums ，请你找出其中 没有出现 的最小的正整数。

请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
1 <= nums.length <= 5e5
-2^31 <= nums[i] <= 2^31 - 1

方法一：原地哈希

将数组所有的数放入哈希表，随后从 1 开始依次枚举正整数，并判断其是否在哈希表中。

实际上，对于一个长度为 N 的数组，其中没有出现的最小正整数只能在 [1,N+1] 中

比如 nums = [1,2,3] n = 3 此时缺失的最小的正整数是 4

对数组进行遍历，对于遍历到的数 x，如果它在 [1,N] 的范围内，那么就将数组中的第 x−1 个位置
（注意：数组下标从 0 开始）打上「标记」。
在遍历结束之后，如果所有的位置都被打上了标记，那么答案是 N+1，否则答案是最小的没有打上标记的位置加 1。

把不在 [1,N] 范围内的数修改成任意一个大于 N 的数（例如 N+1）
数组中的所有数就都是正数了，因此我们就可以将「标记」表示为「负号」。

将数组中所有小于等于 0 的数修改为 N+1

遍历数组中的每一个数 x，它可能已经被打了标记，对应的数为 abs(x)。如果 ∣x∣∈[1,N] 
那么我们给数组中的第 ∣x∣−1 个位置的数添加一个负号。注意如果它已经有负号，不需要重复添加；

在遍历完成之后，如果数组中的每一个数都是负数，那么答案是 N+1，否则答案是第一个正数的位置加 1。

具体做法：
遍历数组，将所有小于等于 0 的数修改为 N+1  // 因为是找最小的正数，将负数标记为 N + 1 或任意大数
再次遍历数组，取 abs(nums[i])，如果 abs(nums[i]) <= n 则将其放到 nums[nums[i] - 1] 并且打上负号标记
再次遍历数组，如果 nums[i] > 0 则表示 i + 1 这个数不在数组中，返回即可
再次回顾，如果之前是负数，此时 nums[i] = N + 1，不是负数，表示 i + 1 没出现
打上负号的表示是出现过


 */
class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for (int& num : nums) {
      if (num <= 0) {
        num = n + 1;
      }
    }
    for (int i = 0; i < n; i++) {
      int num = abs(nums[i]);                 // 为什么还要取 abs，因为有可能被之前的打过标记
      if (num <= n) {                         // 出现在范围内，表示是出现过的正数
        nums[num - 1] = -abs(nums[num - 1]);  // 如果小于 n 则存在，原地哈希记录 mp[num - 1] 出现过
      }
    }
    for (int i = 0; i < n; i++) {
      if (nums[i] > 0) {
        return i + 1;
      }
    }
    return n + 1;
  }
};
int main() {

  Solution test;
  vector<int> nums = {-1, -2, -3, -4};
  cout << test.firstMissingPositive(nums) << endl;
  return 0;
}