#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

/*
 * @lc app=leetcode.cn id=2865 lang=cpp
 *
 * [2865] 美丽塔 I
 *
 * https://leetcode.cn/problems/beautiful-towers-i/description/
 *
 *
 * 给你一个长度为 n 下标从 0 开始的整数数组 maxHeights 。
 * 
 * 你的任务是在坐标轴上建 n 座塔。第 i 座塔的下标为 i ，高度为 heights[i] 。
 * 
 * 如果以下条件满足，我们称这些塔是 美丽 的：
 * 
 * 
 * 1 <= heights[i] <= maxHeights[i]
 * heights 是一个 山脉 数组。
 * 
 * 
 * 如果存在下标 i 满足以下条件，那么我们称数组 heights 是一个 山脉 数组：
 * 
 * 
 * 对于所有 0 < j <= i ，都有 heights[j - 1] <= heights[j]
 * 对于所有 i <= k < n - 1 ，都有 heights[k + 1] <= heights[k]
 * 
 * 
 * 请你返回满足 美丽塔 要求的方案中，高度和的最大值 。
 * 
 * 
 * 输入：maxHeights = [5,3,4,1,1]
 * 输出：13
 * 解释：和最大的美丽塔方案为 heights = [5,3,3,1,1] ，这是一个美丽塔方案，因为：
 * - 1 <= heights[i] <= maxHeights[i]  
 * - heights 是个山脉数组，峰值在 i = 0 处。
 * 13 是所有美丽塔方案中的最大高度和。
 * 
 * 输入：maxHeights = [6,5,3,9,2,7]
 * 输出：22
 * 解释： 和最大的美丽塔方案为 heights = [3,3,3,9,2,2] ，这是一个美丽塔方案，因为：
 * - 1 <= heights[i] <= maxHeights[i]
 * - heights 是个山脉数组，峰值在 i = 3 处。
 * 22 是所有美丽塔方案中的最大高度和。
 * 
 * 
 * 输入：maxHeights = [3,2,5,5,2,3]
 * 输出：18
 * 解释：和最大的美丽塔方案为 heights = [2,2,5,5,2,2] ，这是一个美丽塔方案，因为：
 * - 1 <= heights[i] <= maxHeights[i]
 * - heights 是个山脉数组，最大值在 i = 2 处。
 * 注意，在这个方案中，i = 3 也是一个峰值。
 * 18 是所有美丽塔方案中的最大高度和。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n == maxHeights <= 10^3
 * 1 <= maxHeights[i] <= 10^9
 * 
 * 
 * 方法一：枚举 On^2
 * 为了使得每个 1 <= h[i] <= mh[i] 并且其是山峰
 * 贪心不对，如果只找一个最大值，很可能最大值在两侧 3,6,3,5,5,1,2,5,5,6
 * 无法确定是哪个最大值，所以最好遍历 + 枚举
 * 考虑暴力的方法每次枚举 mh[i] 为山顶，求出最大和
 * 遍历到 mh[i] 时候，从 i 到 0 维护递减，i 到 n-1 维护递减
 * 
 * 方法二：单调栈
 * 实际上可以用单调栈维护 
 * mh[:i] 的 非递减 数组的最大和 pre[i]
 * mh[i:] 的 非递增 数组的最大和 suf[i]
 * 此时遍历 mh[:]，求解 max(ans, pre[i] + suf[i]) 即是答案
 * 
 * 为什么用单调栈？因为维护单调性
 * 
 * 对于 pre[i] 表示从 i 到 n-1 的最大非递增数组和
 * 如果 mh[i] 小于栈顶对应数，表示从 i 到 j 这段必须全是 mh[i]
 * 则需要减去栈顶的数 * 间隔，循环直到大于等于栈顶，入栈下标
 * 例子：3 6 5 2 1 对于 3 要弹出 6下标 5下标 表示非递增数组 3 3 3 2 1
 * 
 * 对于 suf[i]
 * 需要从后往前遍历，反过来则同样是维护非递减
 *
 * 
 * 
 */

// @lc code=start
typedef long long ll;
class Solution {
 public:
  long long maximumSumOfHeights(vector<int>& maxHeights) {
    int n = maxHeights.size();
    vector<ll> suf(n);
    stack<int> stk;
    stk.emplace(n);  // 处理最后一个
    ll sum = 0;
    for (int i = n - 1; i >= 0; i--) {
      int cur = maxHeights[i];
      while (stk.size() > 1 && cur <= maxHeights[stk.top()]) {
        int j = stk.top();
        stk.pop();
        // 当前的前一个较大值小，为了从后往前维护非递减
        // 需要弹出该值，于是 j 到前前一个较大值之间的和被替换
        sum -= 1LL * maxHeights[j] * (stk.top() - j);
      }
      // height[i:j] -> cur cur cur cur
      sum += 1LL * cur * (stk.top() - i);
      suf[i] = sum;
      stk.emplace(i);
    }
    stk = stack<int>();  // clear
    stk.emplace(-1);     // 处理第一个
    ll ans = sum;        // 第一个
    ll pre = 0;
    for (int i = 0; i < n; i++) {
      int cur = maxHeights[i];
      while (stk.size() > 1 && cur <= maxHeights[stk.top()]) {
        // cout << cur << " " << maxHeights[stk.top()] << endl;
        int j = stk.top();
        stk.pop();
        pre -= 1LL * maxHeights[j] * (j - stk.top());
      }
      pre += 1LL * cur * (i - stk.top());
      ans = max(ans, pre + suf[i] - cur);
      stk.emplace(i);
    }
    return ans;
  }
};
// @lc code=end
int main() {

  Solution test;
  //   vector<int> a = {5, 3, 4, 1, 1};
  vector<int> a = {1000000000, 1000000000, 1000000000};
  cout << test.maximumSumOfHeights(a) << endl;
  return 0;
}