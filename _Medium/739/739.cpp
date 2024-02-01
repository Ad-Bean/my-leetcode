#include <bits/stdc++.h>
using namespace std;

/*

[739] 每日温度
https://leetcode.cn/problems/daily-temperatures/description/

给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。
如果气温在这之后都不会升高，请在该位置用 0 来代替。

输入: temperatures = [73,74,75,71,69,72,76,73]
输出: [1,1,4,2,1,1,0,0]

answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。
如果气温在这之后都不会升高，请在该位置用 0 来代替。

为什么要用单调栈？因为可以维护一个单调性质

方法一：从后向前
从后向前，对每个数，如果这个数大于栈顶，弹出直到 栈空 或者当前数小于栈顶。
小于栈顶，就表示当前数**下一个较大值**就是栈顶。
因为如果栈顶数小于当前数，该数不可能是当前数的下一个较大值，同时也不可能是当前数往前的较大值（只可能是当前或更后的）
用栈记录值和下标

方法二：从前向后
栈中记录还没算出「下一个更大元素」的那些数（的下标）,单调递减栈

 */
typedef long long ll;
typedef pair<int, int> pii;
class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    stack<pair<int, int>> stk;
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
      // 从后向前，维护单调栈 单调递减，所以栈顶弹出 比当前小的
      while (!stk.empty() && stk.top().first <= temperatures[i]) {
        stk.pop();
      }
      if (!stk.empty()) {
        ans[i] = stk.top().second - i;
      }
      stk.push({temperatures[i], i});
    }
    return ans;
  }
};
int main() {

  Solution test;
  vector<int> t = {73, 74, 75, 71, 69, 72, 76, 73};
  auto ans = test.dailyTemperatures(t);
  for (const auto a : ans) {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}
