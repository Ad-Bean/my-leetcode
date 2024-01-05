#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
有 n 个人排成一个队列，从左到右 编号为 0 到 n - 1 。给你以一个整数数组 heights ，每个整数 互不相同，heights[i] 表示第 i 个人的高度。

一个人能 看到 他右边另一个人的条件是这两人之间的所有人都比他们两人 矮 。更正式的，第 i 个人能看到第 j 个人的条件是 i < j 且 min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], ..., heights[j-1]) 。

请你返回一个长度为 n 的数组 answer ，其中 answer[i] 是第 i 个人在他右侧队列中能 看到 的 人数 。
1 <= n <= 1e5 heights 中所有数 互不相同 。
输入：heights = [10,6,8,5,11,9]
输出：[3,1,2,1,1,0]


如果 On^2 暴力遍历
对每个 i 找右边每个 j，找第一个大于等于 h[i] 的下标求出间隔 j - i - 1
超时，尝试使用单调栈

方法一：单调栈
单调栈，维护单调递减，并且从右往左遍历
对 9，入栈 9，更新 ans[i] = 0
对 11，大于栈顶 9，弹出，更新 ans[i] = 1，入栈
对 5，小于栈顶 11，入栈，更新 ans[i] = 0，
对 8，大于栈顶 5，弹出，小于栈顶 11，入栈，更新 ans[i] = 2，
对 6，小于栈顶 8，入栈，更新 ans[i] = 1
对 10，大于栈顶 6，弹出，大于栈顶 8，弹出，小于栈顶 11，更新 ans[i] = 3

此时单调栈是单调递减，表示当前 h[i] 往右看的一个递增序列，单调栈的大小就是人数，每次弹出记录的是人数 ++

 */
class Solution {
 public:
  vector<int> canSeePersonsCount(vector<int>& heights) {
    int n = heights.size();
    vector<int> ans(n);
    vector<int> stk;
    stk.emplace_back(n - 1);
    for (int i = n - 2; i >= 0; i--) {
      while (!stk.empty() && heights[stk.back()] < heights[i]) {
        stk.pop_back();
        ans[i]++;
      }
      if (!stk.empty()) {
        ans[i]++;
      }
      stk.emplace_back(i);
    }
    return ans;
  }
};
int main() {

  Solution test;
  vector<int> h = {10, 6, 8, 5, 11, 9};
  vector<int> a = test.canSeePersonsCount(h);
  for (const auto i : a) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
