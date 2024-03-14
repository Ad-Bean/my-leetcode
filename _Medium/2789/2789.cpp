#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
/* 
给你一个下标从 0 开始、由正整数组成的数组 nums 。

你可以在数组上执行下述操作 任意 次：

选中一个同时满足 0 <= i < nums.length - 1 和 nums[i] <= nums[i + 1] 的整数 i 。
将元素 nums[i + 1] 替换为 nums[i] + nums[i + 1] ，并从数组中删除元素 nums[i] 。
返回你可以从最终数组中获得的 最大 元素的值。

输入：nums = [2,3,7,9,3]
输出：21
解释：我们可以在数组上执行下述操作：
- 选中 i = 0 ，得到数组 nums = [5,7,9,3] 。    
- 选中 i = 1 ，得到数组 nums = [5,16,3] 。
- 选中 i = 0 ，得到数组 nums = [21,3] 。
最终数组中的最大元素是 21 。可以证明我们无法获得更大的元素。

方法一：贪心 + 倒序
让左边尽可能小
从后往前遍历：如果当前 nums[i] < cur 则加上 nums[i]，否则更新 cur 为 nums[i]
[2,3,7,9,3]
[2,3,16,3]
[2,19,3]
[21,3]

 */
class Solution {
  typedef long long ll;

 public:
  long long maxArrayValue(vector<int>& nums) {
    int n = nums.size();
    ll cur = nums[n - 1];  //  nums.back();
    for (int i = n - 2; i >= 0; i--) {
      if (nums[i] <= cur) {
        cur += nums[i];
      } else {
        cur = nums[i];
      }
    }
    return cur;
  }
};
int main() {

  Solution test;
  vector<int> t = {2, 3, 7, 9, 3};
  cout << test.maxArrayValue(t) << endl;
  return 0;
}
