#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
我们称一个分割整数数组的方案是 好的 ，当它满足：

数组被分成三个 非空 连续子数组，从左至右分别命名为 left ， mid ， right 。
left 中 元素和 小于等于 mid 中 元素和，mid 中 元素和 小于等于 right 中 元素和。
给你一个 非负 整数数组 nums ，请你返回 好的 分割 nums 方案数目。
由于答案可能会很大，请你将结果对 1e9 + 7 取余后返回。
输入：nums = [1,2,2,2,5,0]
输出：3
解释：nums 总共有 3 种好的分割方案：
[1] [2] [2,2,5,0]
[1] [2,2] [2,5,0]
[1,2] [2,2] [5,0]

3 <= nums.length <= 1e5

方法一：前缀和 + 二分
数据范围是 10^5 因此只能使用低于等于 NlogN 的算法
1. 遍历 + 二分
2. 排序

思考怎么分成三组
假设已经有 l, 为了让 m 的和 >= l 的和，且 m 的和 <= r 的和
Sl <= Sr - Sl <= Sn - Sr
由于前缀和数组递增，可以枚举 r 在前面二分找一个 l 有
Sl >= 2Sr + Sn 第一个大于等于 2Sr + Sn 的位置，此时 Sl <= Sn - Sr 第一个区间满足条件
2 * Sl <= Sr   
那么可以找到一个 l 大于 Sr / 2 的位置，则前面都满足条件 Sl <= Sr - Sl
于是 l1 到 l2 都满足条件，计入答案

通过枚举 r，使用二分找到满足条件的 l

优化：r的范围 3*pre[r] <= 2*pre[n] 因为 2 <= r < n 且 2Sr <= Sn + Sl <= Sn + Sr / 2
3/2 Sr <= Sn 所以 3*pre[r] <= 2*pre[n]

另：也可以枚举 l，一样
 */
class Solution {
  const int mod = 1e9 + 7;

 public:
  int waysToSplit(vector<int>& nums) {
    int n = nums.size();
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
      pre[i] = pre[i - 1] + nums[i - 1];
    }
    int ans = 0;
    for (int r = 2; r < n && 3 * pre[r] <= 2 * pre[n]; r++) {
      int l1 = lower_bound(pre.begin() + 1, pre.begin() + r, 2 * pre[r] - pre[n]) - pre.begin();
      int l2 = upper_bound(pre.begin(), pre.begin() + r, pre[r] / 2) - pre.begin();
      ans = (ans + l2 - l1) % mod;
    }
    return ans % mod;
  }
};

int main() {

  Solution test;
  return 0;
}
