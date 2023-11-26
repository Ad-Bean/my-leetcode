#include <bits/stdc++.h>
using namespace std;

/* 
找到数组中操作 k 次自增后，最大的频数

排序，如果可以将 x[i:i+k] 全部变成 y。如果最大值为 x 那么一定全部变成 x，操作数更少？
优先操作，距离目标值更近的元素 -> 二分
 */
class Solution {
  typedef long long ll;

 public:
  int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int l = 0;
    ll sum = 0;
    int res = 1;
    for (int r = 1; r < n; r++) {
      sum += ((ll)nums[r] - (ll)nums[r - 1]) * (r - l);
      while (sum > k) {
        sum -= nums[r] - nums[l];
        ++l;
      }
      res = max(res, r - l + 1);
    }
    return res;
  }
};
int main() {

  Solution test;
  return 0;
}