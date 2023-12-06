#include <bits/stdc++.h>
using namespace std;
/* 
无向、无根树，
每个节点 price[i]

给定路径的 价格总和 是路径上所有结点的价格之和

trips[i] = [start, end] 执行 第一次 旅行前可以选择一些，非相邻结点，价格减半

返回所有旅行的最小价格总和


输入：n = 4, edges = [[0,1],[1,2],[1,3]], price = [2,2,10,6], trips = [[0,3],[2,1],[2,3]]
输出：23

输入：n = 2, edges = [[0,1]], price = [2,2], trips = [[0,0]]
输出：1

方法一：DFS + DP
trips[i] 为了使得路径和最小，必须是最短的
遍历 trips[i], 记录 count[i] 结点 i 被经过的次数，从 start 开始为根，dfs 树
pricesTotal = \sum {price[node] * count[node]}

dp[node][0] dp[node][1] 表示以 node 为根节点，保持价格或者减半

dp[node][0] = \sum min(dp[child][0], dp[child][1])
dp[node][1] = \sum dp[child][0]

方法二：树形 DP
方法三：Tarjan(LCA) + DP
 */
typedef long long ll;
typedef pair<int, int> pii;

class Solution {
 public:
  int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
    vector<vector<int>> g(n);
    for (const auto& e : edges) {
      g[e[0]].emplace_back(e[1]);
      g[e[1]].emplace_back(e[0]);
    }

    vector<int> cnt(n);
    function<bool(int, int, int)> dfs = [&](int node, int parent, int end) -> bool {
      if (node == end) {
        cnt[node]++;
        return true;
      }
      for (const int& child : g[node]) {
        if (child == parent) {
          continue;
        }
        if (dfs(child, node, end)) {
          cnt[node]++;
          return true;
        }
      }
      return false;
    };
    for (const auto& trip : trips) {
      dfs(trip[0], -1, trip[1]);
    }
    // 递推？
    function<pii(int, int)> dp = [&](int node, int parent) -> pii {
      pii res = {price[node] * cnt[node], price[node] * cnt[node] / 2};
      for (const int& child : g[node]) {
        if (child == parent) {
          continue;
        }
        auto [x, y] = dp(child, node);
        res.first += min(x, y);  // 不减半
        res.second += x;         // 减半
      }
    };
    auto [x, y] = dp(0, -1);
    return min(x, y);
  }
};
int main() {

  Solution test;
  return 0;
}
