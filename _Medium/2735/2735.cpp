#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
/* 
给你一个长度为 n 、下标从 0 开始的整数数组 nums ，表示收集不同巧克力的成本。
每个巧克力都对应一个不同的类型，最初，位于下标 i 的巧克力就对应第 i 个类型。

在一步操作中，你可以用成本 x 执行下述行为：

同时修改所有巧克力的类型，将巧克力的类型 ith 修改为类型 ((i + 1) mod n)th。
假设你可以执行任意次操作，请返回收集所有类型巧克力所需的最小成本。


输入：nums = [20,1,15], x = 5
输出：13
解释：最开始，巧克力的类型分别是 [0,1,2] 。我们可以用成本 1 购买第 1 个类型的巧克力。
接着，我们用成本 5 执行一次操作，巧克力的类型变更为 [1,2,0] 。我们可以用成本 1 购买第 2 个类型的巧克力。
然后，我们用成本 5 执行一次操作，巧克力的类型变更为 [2,0,1] 。我们可以用成本 1 购买第 0 个类型的巧克力。
因此，收集所有类型的巧克力需要的总成本是 (1 + 5 + 1 + 5 + 1) = 13 。可以证明这是一种最优方案。

方法一：贪心
枚举操作次数，0 到 n-1 
如果不操作，则第i个花费 nums[i]，此时总花费 sum(nums[i])
如果只操作一次，则取 min(nums[i], nums[(i+1)%n])
如果操作两次，则取 min(nums[i], nums[(i+1)%n], nums[(i+2)%n])

如果暴力枚举操作次数，再枚举每个巧克力，再计算购买这个巧克力的最小花费，总的时间复杂度是 O(n^3)
用 O(n^2)的时间预处理所有子数组的最小值，保存到一个二维数组中。这样做需要 O(n^2) 的时间和空间。

但可以用长度为 n 的数组统计不同操作次数下的总成本
使用二重循环，枚举子数组左端点 i， 右端点 j
枚举右端点同时，维护 nums[i] 到 nums[j] 的最小值 minn
将 minn 加到 s[j-i] 中，表示 j-i+1 长度的子数组对应操作 j-i 次时要计算的子数组
最后输出 min(s)
*/
class Solution {
  typedef long long ll;

 public:
  long long minCost(vector<int>& nums, int x) {
    int n = nums.size();
    vector<ll> s(n);  // 操作 i 次的总成本
    for (int i = 0; i < n; i++) {
      s[i] = (ll)i * x;
    }
    for (int i = 0; i < n; i++) {
      int minn = nums[i];                // 左端点
      for (int j = i; j < n + i; j++) {  // 右端点，环形数组
        minn = min(minn, nums[j % n]);   // 找到 nums[i:j] 最小值
        s[j - i] += minn;                // 移动 j-i 的成本
      }
    }
    return *min_element(s.begin(), s.end());
  }
};
int main() {

  Solution test;
  vector<int> nums = {20, 1, 15};
  int x = 5;
  cout << test.minCost(nums, x) << endl;
  return 0;
}
