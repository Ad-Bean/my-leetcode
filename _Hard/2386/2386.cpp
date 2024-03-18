#include <bits/stdc++.h>
using namespace std;

/* 
给你一个整数数组 nums 和一个 正 整数 k 。你可以选择数组的任一 子序列 并且对其全部元素求和。

数组的 第 k 大和 定义为：可以获得的第 k 个 最大 子序列和（子序列和允许出现重复）

返回数组的 第 k 大和 。

子序列是一个可以由其他数组删除某些或不删除元素排生而来的数组，且派生过程不改变剩余元素的顺序。

注意：空子序列的和视作 0 。

输入：nums = [2,4,-2], k = 5
输出：2
解释：所有可能获得的子序列和列出如下，按递减顺序排列：
- 6、4、4、2、2、0、0、-2
数组的第 5 大和是 2 。

方法一：堆
转换：计算 nums 中所有非负数的和 sum
nums 的任意一个子序列的和，都等价于 sum 减去某些非负数 / 加上某些负数得到
nums=[1,2,3,−4]
sum = 6
sum - 2 = 4 就是子序列 [1,3] 1+3 的和
sum + -4 = 2 就是子序列 [2] 的和
sum - 1 - 2 - 3 + -4 = -4 就是子序列 [-4] 的和
减去非负数 == 加上负数，所以把负数变成非负数，对非负数求和

如何找到 nums 的所有子序列
nums = [-2,2,4]，一共 2^3 = 8 个子序列
[]                                  0_
[2]                                 2_
[2, 2]  [2]                         4  2_
[2, 4]  [4]                         6  4_


计算了前 k-1 个最小的子序列和分别是 0 2 2 4 (转换后的)
此时 pq.top().first 是第 k-1 个最小的子序列和 4 [2,2]
sum 6 - 4 = 2 即第 k 大的子序列和 
6、4、4、2、2、0、0、-2

这个转换思想实在是难，不知道怎么想出来的
为什么数组子序列和第 k 大就是 数组非负数之和 减去第 k-1 个最小的子序列和？
nums 的任意一个子序列的元素和，都等价于从非负数之和 sum 中减去某些非负数 / 加上某些负数得到。

因为 sum 是非负数之和，所以 sum 就是最大的子序列和
第 2 大的子序列和就是 sum 减去第 1 小的子序列和（绝对值最小，所以可以转换）

 */
class Solution {
  typedef pair<long, int> pli;

 public:
  long long kSum(vector<int>& nums, int k) {
    long sum = 0;
    for (auto& num : nums) {
      if (num >= 0) {
        sum += num;
      } else {
        num = -num;
      }
    }
    ranges::sort(nums);
    // 用小根堆 枚举前 k 个最小的子序列和
    priority_queue<pli, vector<pli>, greater<>> pq;        // 小根堆
    pq.emplace(0, 0);                                      //
    while (--k) {                                          // 先计算 k-1 个最小的子序列和，从小到大
      auto [sum, i] = pq.top();                            //
      cout << sum << " " << i << endl;                     //
      pq.pop();                                            //
      if (i < nums.size()) {                               //
        pq.emplace(sum + nums[i], i + 1);                  // 添加
        if (i) {                                           // 不为空
          pq.emplace(sum - nums[i - 1] + nums[i], i + 1);  // 替换最后一个元素
        }                                                  //
      }                                                    //
    }                                                      //
    cout << pq.top().first << endl;                        //
    return sum - pq.top().first;                           // 此时 pq.top().first 是第 k 个最小的子序列和
  }
};

int main() {

  Solution test;
  vector<int> nums = {2, 4, -2};
  int k = 5;
  cout << test.kSum(nums, k) << endl;
  while (--k) {
    cout << "test" << endl;
  }
  return 0;
}
