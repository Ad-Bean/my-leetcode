
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
/* 
给你一个长度为 n 下标从 0 开始的整数数组 maxHeights 。

你的任务是在坐标轴上建 n 座塔。第 i 座塔的下标为 i ，高度为 heights[i] 。

如果以下条件满足，我们称这些塔是 美丽 的：

1 <= heights[i] <= maxHeights[i]
heights 是一个 山脉 数组。
如果存在下标 i 满足以下条件，那么我们称数组 heights 是一个 山脉 数组：

对于所有 0 < j <= i ，都有 heights[j - 1] <= heights[j]
对于所有 i <= k < n - 1 ，都有 heights[k + 1] <= heights[k]
请你返回满足 美丽塔 要求的方案中，高度和的最大值 。

输入：maxHeights = [5,3,4,1,1]
输出：13
解释：和最大的美丽塔方案为 heights = [5,3,3,1,1] 

方法一：单调栈
如果用 heights[i] 中的最大值，则左右的值均小于等于该值
对 [0, i-1] 有 heights[i] = min(heights[i+1], maxHeights[i])
对 [i+1, n-1] 有 heights[i] = min(heights[i-1], maxHeights[i])

!贪心为什么是错的：
如果直接取最大值为 heights[i]，中心扩散
对于样例 [6,5,2,1,5,4,4,2] 如果取最大值 6，形成 [6 5 2 1 1 1 1 1] 和为 18
但是错的，更大的为 [ 1 1 1 1 5 4 4 2] 和为 19

要求的是对 heights[:i] 形成左侧递增和 h[i:] 形成右侧递减
最后的答案就是 pre[i] + suf[i + 1]
 */
class Solution {
  typedef long long ll;

 public:
  long long maximumSumOfHeights(vector<int>& maxHeights) {
    int n = maxHeights.size();
    vector<ll> suf(n + 1);
    stack<int> stk;
    stk.emplace(n);
    ll sum = 0;
    for (int i = n - 1; i >= 0; i--) {
      // 从后往前单调递增，单调栈也单调递增，当前小于栈顶，则弹出
      // 并且这一段的和都是小的值
      while (stk.size() > 1 && maxHeights[stk.top()] > maxHeights[i]) {
        int j = stk.top();
        stk.pop();
        // 3 4 6 6 1 上一段要变成新的，去掉
        sum -= 1LL * maxHeights[j] * (stk.top() - j);
      }
      // 当前到第一个小于该数的值之间，都可以为该数比如 7 9 9 9 9 9 1
      sum += 1LL * maxHeights[i] * (stk.top() - i);
      suf[i] = sum;
      stk.emplace(i);
    }
    ll ans = sum;
    stk = stack<int>();
    stk.emplace(-1);
    ll pre = 0;
    for (int i = 0; i < n; i++) {
      while (stk.size() > 1 && maxHeights[stk.top()] > maxHeights[i]) {
        int j = stk.top();
        stk.pop();
        pre -= 1LL * maxHeights[j] * (j - stk.top());
      }
      // 当前到第一个小于该数的值之间，都可以为该数比如 7 9 9 9 9 9 1
      pre += 1LL * maxHeights[i] * (i - stk.top());
      stk.emplace(i);
      ans = max(ans, pre + suf[i + 1]);
    }
    return ans;
  }
};
int main() {

  Solution test;
  vector<int> h = {5, 3, 4, 1, 1};
  cout << test.maximumSumOfHeights(h) << endl;
  return 0;
}