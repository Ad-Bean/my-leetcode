#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
树是一个无向图，其中任何两个顶点只通过一条路径连接。 
换句话说，一个任何没有简单环路的连通图都是一棵树。

给你一棵包含 n 个节点的树，标记为 0 到 n - 1 。
给定数字 n 和一个有 n - 1 条无向边的 edges 列表（每一个边都是一对标签），
其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条无向边。

可选择树中任何一个节点作为根。当选择节点 x 作为根节点时，设结果树的高度为 h 。
在所有可能的树中，具有最小高度的树（即，min(h)）被称为 最小高度树 。

请你找到所有的 最小高度树 并按 任意顺序 返回它们的根节点标签列表。

树的 高度 是指根节点和叶子节点之间最长向下路径上边的数量。
1 <= n <= 2 * 1e4

方法一：BFS
暴力的想，从每个结点 BFS 一遍，看层数就是高度，然后找最小的
n^2 复杂度，不能接受。
对树上距离最长的两个节点 x 和 y，直径的一半一定是在 x 到 y 的路径上的，
则最小高度一定是直径 / 2，所以可以找到直径的两个端点
最小高度树的根节点一定是直径的中点，或者是两个


方法二：拓扑排序
将所有度为 1 的点入队列，剩余节点 remain = n
remain 减去度为 1 的点，将最外层度为 1 的叶子节点取出，减少相邻节点度，重复这两步
直到 remain <= 2

拓扑和 BFS 的思想类似，从外向内，每次减少一层，直到找到中间的点

 */
class SolutionBFS {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) {
      return {0};
    }
    if (n == 2) {
      return {0, 1};
    }
    vector<vector<int>> g(n);
    for (const auto& e : edges) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }
    vector<int> parent(n, -1);
    function<int(int)> bfs = [&](int u) {
      queue<int> q;
      vector<int> vis(n);
      q.emplace(u);
      vis[u] = 1;
      int node = -1;
      while (!q.empty()) {
        int cur = q.front();
        q.pop();
        node = cur;
        for (auto& nx : g[cur]) {
          if (!vis[nx]) {
            q.emplace(nx);
            vis[nx] = 1;
            parent[nx] = cur;
          }
        }
      }
      return node;  // 最远的点
    };
    // 直径两点
    int x = bfs(0);
    int y = bfs(x);
    vector<int> path;
    parent[x] = -1;
    while (y != -1) {
      path.emplace_back(y);
      y = parent[y];
    }
    int m = path.size();
    if (m % 2 == 0) {
      return {path[m / 2], path[m / 2 - 1]};
    } else {
      return {path[m / 2]};
    }
  }
};

class SolutionTopo {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) { int }
};

int main() {

  Solution test;
  return 0;
}
