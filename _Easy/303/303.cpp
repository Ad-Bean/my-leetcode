#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给定一个整数数组  nums，处理以下类型的多个查询:

计算索引 left 和 right （包含 left 和 right）之间的 nums 元素的 和 ，其中 left <= right
实现 NumArray 类：

NumArray(int[] nums) 使用数组 nums 初始化对象
int sumRange(int i, int j) 返回数组 nums 中索引 left 和 right 之间的元素的 总和 ，
包含 left 和 right 两点（也就是 nums[left] + nums[left + 1] + ... + nums[right] )

方法一：前缀和
 */
class NumArray {
  vector<int> pre;

 public:
  NumArray(vector<int>& nums) {
    int n = nums.size();
    pre.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      pre[i] = pre[i - 1] + nums[i - 1];
    }
  }

  int sumRange(int l, int r) { return pre[r + 1] - pre[l]; }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
int main() {

  Solution test;
  return 0;
}
