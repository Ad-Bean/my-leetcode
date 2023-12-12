#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
给你一个下标从 0 开始的非负整数数组 nums 。对于 nums 中每一个整数，你必须找到对应元素的 第二大 整数。

方法一：单调栈 + 优先队列
首先计算每个数字的下一个比他大的数，单调栈
用栈存储元素下标，
如果当前元素大于栈顶对应的值，则找到了栈顶元素下一个更大的数字，出栈更新结果
如果当前元素小于栈顶对应元素，则入栈
维持栈单调递减

怎么找到第二大？
引入 最小堆，存储已经找到下一个更大值的 数组元素
1. 如果 heap 非空，且堆顶元素小于当前元素，则堆顶找到了第二大，弹出堆顶，循环这个过程直到 堆空 或 堆顶元素大于等于当前元素
2. 如果 stk  非空，且栈顶元素小于当前元素，则栈顶找到了下一个大，弹出栈，循环这个过程直到 栈空 或 栈顶元素大于等于当前元素
3. 入栈

方法二：双单调栈

 */
class Solution {
  typedef pair<int, int> pii;

 public:
  vector<int> secondGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> stk;
    priority_queue<pii, vector<pii>, greater<pii>> hp;
    for (int i = 0; i < n; i++) {
      while (!hp.empty() && hp.top().first < nums[i]) {
        // 堆顶找到了第二大
        ans[hp.top().second] = nums[i];
        hp.pop();
      }
      while (!stk.empty() && nums[stk.top()] < nums[i]) {
        // 栈顶找到了下一个大
        hp.emplace(nums[stk.top()], stk.top());  // nums[i],i
        stk.pop();
      }
      stk.emplace(i);
    }
    return ans;
  }
};
int main() {
  Solution test;
  vector<int> nums = {2, 4, 0, 9, 6};
  auto ans = test.secondGreaterElement(nums);
  for (const auto i : ans) {
    cout << i << " ";
  }
  return 0;
}
