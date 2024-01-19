#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。


方法二：分治
类似线段树求解最长公共上升子序列的 pushUp
get(a, l, r) 表示 a[l:r] 区间内的最大字段和
求 get(a, 0, n-1)

 */
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    function<vector<int>(vector<int>, vector<int>)> pushUp = [&](vector<int> l, vector<int> r) -> vector<int> {
      int isum = l[3] + r[3];
      int lsum = max(l[0], l[3] + r[0]);
      int rsum = max(r[1], r[3] + l[1]);
      int msum = max(max(l[2], r[2]), l[1] + r[0]);
      return {lsum, rsum, msum, isum};
    };
    function<vector<int>(int, int)> get = [&](int l, int r) -> vector<int> {
      if (l == r) {
        return {nums[l], nums[l], nums[l], nums[l]};
      }
      int m = (l + r) >> 1;
      auto lsub = get(l, m);
      auto rsub = get(m + 1, r);
      return pushUp(lsub, rsub);
    };
    return get(0, n - 1)[3];
  }
};
int main() {

  Solution test;
  return 0;
}