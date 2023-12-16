#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
给你一个数组 nums ，请你完成两类查询。

其中一类查询要求 更新 数组 nums 下标对应的值
另一类查询要求返回数组 nums 中索引 left 和索引 right 之间（ 包含 ）的nums元素的 和 ，其中 left <= right


方法一：线段树
单点更新，区间查询

 */
class NumArray {
  int n;
  vector<int> sum;

  void build(vector<int>& nums, int o, int l, int r) {
    if (l == r) {
      sum[o] = nums[l];
      return;
    }
    int m = l + (r - l) / 2;
    build(nums, o * 2 + 1, l, m);
    build(nums, o * 2 + 2, m + 1, r);
    sum[o] = sum[o * 2 + 1] + sum[o * 2 + 2];
  }

  int query(int o, int l, int r, int L, int R) {
    if (L <= l && r <= R) {  //如果查询区间包含当前区间 [L lr R]，停止递归
      return sum[o];
    }
    int m = l + (r - l) / 2;
    int summ = 0;
    if (L <= m) {
      summ += query(o * 2 + 1, l, m, L, R);
    }
    if (R > m) {
      summ += query(o * 2 + 2, m + 1, r, L, R);
    }
    return summ;
  }

  // 单点更新 idx
  void change(int idx, int o, int l, int r, int val) {
    if (l == r) {
      sum[o] = val;
      return;
    }
    int m = l + (r - l) / 2;
    if (idx <= m) {
      change(idx, o * 2 + 1, l, m, val);
    } else {
      change(idx, o * 2 + 2, m + 1, r, val);
    }
    sum[o] = sum[o * 2 + 1] + sum[o * 2 + 2];
  }

 public:
  NumArray(vector<int>& nums) {
    n = nums.size();
    sum = vector<int>(n * 4);
    build(nums, 0, 0, n - 1);
  }

  void update(int index, int val) { change(index, 0, 0, n - 1, val); }

  int sumRange(int left, int right) { return query(0, 0, n - 1, left, right); }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
int main() {

  vector<int> nums = {1, 3, 5};
  NumArray* obj = new NumArray(nums);
  cout << obj->sumRange(0, 2) << endl;
  obj->update(1, 2);
  cout << obj->sumRange(0, 2) << endl;
  return 0;
}