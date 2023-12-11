
#include <bits/stdc++.h>
using namespace std;

/* 1287. 有序数组中出现次数超过25%的元素

给你一个非递减的 有序 整数数组，已知这个数组中 恰好有一个整数 ，它的出现次数超过数组元素总数的 25%。

请你找到并返回这个整数

1 <= arr.length <= 10^4


方法一：On 遍历
找 freq * 4 > n

方法二：二分
x 至少出现了 n / 4 + 1 次，
数组 arr 中的元素 arr[0], arr[j], arr[j * 2], ... 一定包含 x。
证明：https://leetcode.cn/problems/element-appearing-more-than-25-in-sorted-array/solutions/101725/you-xu-shu-zu-zhong-chu-xian-ci-shu-chao-guo-25d-3/
 */
typedef long long ll;
typedef pair<int, int> pii;
class Solution {
 public:
  int findSpecialInteger(vector<int>& arr) {

    int n = arr.size();
    int j = n / 4 + 1;
    for (int i = 0; i < n; i += j) {
      auto l = lower_bound(arr.begin(), arr.end(), arr[i]);
      auto r = upper_bound(arr.begin(), arr.end(), arr[i]);
      if (r - l >= j) {
        return arr[i];
      }
    }
    return -1;
  }
};
int main() {

  Solution test;
  return 0;
}