#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
现有一棵由 n 个节点组成的无向树，节点编号从 0 到 n - 1 ，共有 n - 1 条边。

给你一个二维整数数组 edges ，长度为 n - 1 ，其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条边。

另给你一个整数数组 restricted 表示 受限 节点。

在不访问受限节点的前提下，返回你可以从节点 0 到达的 最多 节点数目。

1. restricted 中的所有值 互不相同

注意，节点 0 不 会标记为受限节点。
输入：n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
输出：4
在不访问受限节点的前提下，只有节点 [0,1,2,3] 可以从节点 0 到达。

方法一：BFS / DFS
从 0 开始 DFS / BFS，如果遇到过 or 受限制就跳过

方法二：并查集
忽略受限的点，树就会变成若干个连通块，我们要计算的就是 0 号点所在连通块的大小。
 */
class Solution {
 public:
  int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
    vector<vector<int>> g(n);
    for (const auto& edge : edges) {
      auto u = edge[0], v = edge[1];
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    unordered_map<int, bool> vis;
    for (const auto& i : restricted) {
      vis[i] = true;
    }

    queue<int> que;
    que.emplace(0);
    int ans = 0;
    while (!que.empty()) {
      auto u = que.front();
      ans++;
      vis[u] = true;
      que.pop();
      for (const auto& nx : g[u]) {
        if (vis[nx]) {
          continue;
        }
        que.emplace(nx);
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  int n = 7;
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 1}, {4, 0}, {0, 5}, {5, 6}};
  vector<int> restricted = {4, 5};
  cout << test.reachableNodes(n, edges, restricted) << endl;
  return 0;
}
