#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
给定一个整数数组 arr，找到 min(b) 的总和，其中 b 的范围为 arr 的每个（连续）子数组。

由于答案可能很大，因此 返回答案模 10^9 + 7 。
输入：arr = [3,1,2,4]
输出：17
解释：
子数组为 [3]，[1]，[2]，[4]，[3,1]，[1,2]，[2,4]，[3,1,2]，[1,2,4]，[3,1,2,4]。 
最小值为 3，1，2，4，1，1，2，1，1，1，和为 17。
1 <= arr.length <= 3e4

暴力：枚举所有的子数组
算出每个子数组的最小值

方法一：单调栈


 */
class Solution {
 public:
  int sumSubarrayMins(vector<int>& arr) {
    const int mod = 1e9 + 7;
    int n = arr.size();
    int sum = 0;
    vector<int> stk;
    vector<int> left(n), right(n);
    for (int i = 0; i < n; i++) {
      // 保证 arr[i] 为 从左到右 连续子数组 右边最小的，找到之前第一个小于 arr[i] 的下标
      // 所以单调栈是递增，弹出大于 arr[i] 的值，直到 stk.back() < arr[i]。下标差就是间隔。
      while (!stk.empty() && arr[stk.back()] >= arr[i]) {  // 找到第一个 < 小于 arr[i] 的下标
        stk.pop_back();
      }
      left[i] = stk.empty() ? i + 1 : i - stk.back();
      stk.emplace_back(i);
    }
    cout << "nums: ";
    for (const auto a : arr) {
      cout << a << " ";
    }
    cout << endl;
    cout << "left: ";
    for (const auto a : left) {
      cout << " " << a << " ";
    }
    cout << endl;
    stk.clear();
    for (int i = n - 1; i >= 0; i--) {
      // 保证 arr[i] 为 从右到左 连续子数组 左边最小的，找到之前第一个小于 arr[i] 的下标
      // 所以单调栈是递增，弹出大于 arr[i] 的值，直到 stk.back() < arr[i]。下标差就是间隔。
      while (!stk.empty() && arr[stk.back()] > arr[i]) {
        stk.pop_back();
      }
      right[i] = stk.empty() ? n - i : stk.back() - i;
      stk.emplace_back(i);
    }
    cout << "left: ";
    for (const auto a : right) {
      cout << " " << a << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
      sum = (sum + left[i] * right[i] * arr[i] % mod) % mod;
    }
    return sum;
  }
};

int main() {
  vector<int> arr = {71, 55, 82, 55};
  // vector<int> arr = {3, 1, 2, 4};
  // vector<int> arr = {11, 81, 94, 43, 3};
  Solution test;
  cout << test.sumSubarrayMins(arr) << endl;
  return 0;
}