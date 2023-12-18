
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
峰值元素是指其值严格大于左右相邻值的元素。

给你一个整数数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。

你可以假设 nums[-1] = nums[n] = -∞ 。

你必须实现时间复杂度为 O(log n) 的算法来解决此问题。

方法一：遍历
O(n) 直接返回最大值，必然是峰值

方法二：二分
为什么可以二分: 
如果 nums[m] > nums[m + 1] 那么 nums[m] 可能是峰值而 nums[m + 1] 必然不是，r = m - 1 继续找

1. 一定存在峰值
2. 二分不会错过峰值

证明：对于一个满足 nums[x]>nums[x−1] 的位置，x 的右边一定存在峰值；
或对于一个满足 nums[x]>nums[x+1] 的位置，x 的左边一定存在峰值。


 */
class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    if (nums.size() == 1) {
      return 0;
    }
    int n = nums.size();
    int l = 0, r = nums.size() - 1;                      // [0, n-1]
    while (l <= r) {                                     //
      int m = l + (r - l) / 2;                           //
      if (m + 1 < n && nums[m] < nums[m + 1]) {          //
        l = m + 1;                                       // go to right
      } else if (m - 1 >= 0 && nums[m] < nums[m - 1]) {  //
        r = m - 1;                                       // go to left
      } else {
        return m;
      }
    }
    return r;
  }
};
int main() {

  Solution test;
  vector<int> nums = {1, 2};
  //   vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
  cout << test.findPeakElement(nums) << endl;
  return 0;
}