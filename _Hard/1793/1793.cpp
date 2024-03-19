#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

/* 
给你一个整数数组 nums （下标从 0 开始）和一个整数 k 。

一个子数组 (i, j) 的 分数 定义为 min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1) 。
一个 好 子数组的两个端点下标需要满足 i <= k <= j 。

请你返回 好 子数组的最大可能 分数 。
1 <= nums.length <= 1e5

输入：nums = [1,4,3,7,4,5], k = 3
输出：15
解释：最优子数组的左右端点下标是 (1, 5) ，分数为 min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15 。

输入：nums = [5,5,4,5,4,1,1,1], k = 0
输出：20
解释：最优子数组的左右端点下标是 (0, 4) ，分数为 min(5,5,4,5,4) * (4-0+1) = 4 * 5 = 20 。


方法一：双指针
贪心的想，从 k 向左右扩展，维护当前最小值，维护答案
什么时候停止？当答案不再能更新时
但有时候不知道是先左还是先右：遍历两次

但是还是 WA，算法有问题，应该是先判断 nums[l] nums[r] 是否大于当前最小，才左右走

贪心地往大的走，这样保证 min 值不会变小
但是如果左右都比当前 curMin 小，就要尝试降低 curMin
如果左右到边界，停止
如果左右之一到边界，因为另一边比 curMin 小，更新 curMin
如果左右都没到边界，更新 curMin 为左右中的较大值，继续遍历往大的走

方法二：单调栈

 */
class Solution {
 public:
  int maximumScore(vector<int>& nums, int k) {
    int n = nums.size();
    int curMin = nums[k];
    int l = k - 1, r = k + 1;
    int ans = 0;
    while (true) {
      while (l >= 0 && nums[l] >= curMin) {
        l--;
      }
      while (r < n && nums[r] >= curMin) {
        r++;
      }
      ans = max(ans, curMin * (r - l - 1));   // r - 1 - (l + 1) + 1
      if (l == -1 && r == n) {                // total length
        break;                                //
      }                                       //
      int nextMinL = l == -1 ? -1 : nums[l];  //
      int nextMinR = r == n ? -1 : nums[r];   //
      curMin = max(nextMinL, nextMinR);       // update curMin to the larger one
      if (curMin == -1) {
        break;
      }
    }
    return ans;
  }
};

int main() {

  Solution test;
  //   vector<int> nums = {1, 4, 3, 7, 4, 5};
  //   int k = 3;
  //   cout << test.maximumScore(nums, k) << endl;
  vector<int> nums1 = {8182, 1273, 9847, 6230, 52, 1467, 6062, 726, 4852, 4507, 2460, 2041, 500, 1025, 5524};
  int k1 = 8;
  cout << test.maximumScore(nums1, k1) << endl;
  return 0;
}
