#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
给你一个有 n 个节点的 有向带权 图，节点编号为 0 到 n - 1 。
图中的初始边用数组 edges 表示，其中 edges[i] = [fromi, toi, edgeCosti] 
表示从 fromi 到 toi 有一条代价为 edgeCosti 的边。

请你实现一个 Graph 类：

Graph(int n, int[][] edges) 初始化图有 n 个节点，并输入初始边。
addEdge(int[] edge) 向边集中添加一条边，其中 edge = [from, to, edgeCost] 。
数据保证添加这条边之前对应的两个节点之间没有有向边。

int shortestPath(int node1, int node2) 返回从节点 node1 到 node2 的路径 最小 代价。
如果路径不存在，返回 -1 。一条路径的代价是路径中所有边代价之和。

1 <= n <= 100
0 <= edges.length <= n * (n - 1)

方法一：Dijkstra
求最短路径，且边权为正，有向图，可以考虑使用 Dijkstra
但因为可以向图加边
如果使用 vector<vector<int>> g 存邻接图 g[u].emplace_back(v) 不够，还需要存边权
用 vector<vector<pii>> g 存邻接图，g[u].emplace_back(v, w) w 为边权

Dijkstra 算法：
1. 初始化 dis 数组，dis[u] 表示从 node1 到 u 的最短路径
2. 小根堆 hp 存储 {dis[u], u}
3. 从小根堆中取出 {dis[u], u}，遍历 u 的邻接点 v，如果 dis[v] > dis[u] + w，表示 u 到 nx 的距离可以松弛，则更新 dis[v] = dis[u] + w，将 {dis[v], v} 加入小根堆
4. 重复 3 直到小根堆为空或者取出的节点是 node2

时间复杂度：O(mlogm)，m 为边数，最坏情况下 m = n^2

方法二：Floyd
Floyd 本质是动态规划，求任意两点之间的最短路径
和 Dijkstra 写法区别在于：
不用邻接表，而是直接用邻接矩阵 dis[n][n] 存储任意两点之间的距离
dis[u][v] 表示 u 到 v 的最短路径

int n;
vector<vector<int>> dis;
public:
Graph(int n, vector<vector<int>>& edges) {
    this->n = n;
    dis.resize(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++) {
        dis[i][i] = 0;              // 自己到自己的距离为 0
    }
    for (const auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        dis[u][v] = w;              // 有向图
    }
    for (int k = 0; k < n; k++) {  // Floyd-Warshall
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dis[i][k] != INT_MAX && dis[k][j] != INT_MAX) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);  // k 作为中间点，更新 i -> j 的距离
                }
            }
        }
    }
}

void addEdge(vector<int> edge) {
    int u = edge[0], v = edge[1], w = edge[2];
    if (w >= dis[u][v]) {
        return;      // 如果新加的边权大于等于原来的边权，不用更新
    } 
    for (int i = 0; i < n; i++) {   // 不需要重新计算整个 dis，只需要更新 u -> v 的距离
        for (int j = 0; j < n; j++) {
            if (dis[i][u] != INT_MAX && dis[v][j] != INT_MAX) {
                dis[i][j] = min(dis[i][j], dis[i][u] + dis[v][j] + w); // 表示 i -> u -> v -> j 距离更小
            }
        }
    }
}

int shortestPath(int node1, int node2) {
    return dis[node1][node2] == INT_MAX ? -1 : dis[node1][node2];
}

时间复杂度：O(n^3)
由于本题 n <= 100，所以可以使用 Floyd

 */
class Graph {
  typedef pair<int, int> pii;
  int n;
  vector<vector<pii>> g;  // g[u].emplace_back(v, w) 表示 u -> v 的边权为 w

 public:
  Graph(int n, vector<vector<int>>& edges) {
    this->n = n;
    g.resize(n);
    for (const auto& edge : edges) {
      int u = edge[0], v = edge[1], w = edge[2];
      g[u].emplace_back(v, w);
    }
  }

  void addEdge(vector<int> edge) {
    int u = edge[0], v = edge[1], w = edge[2];
    g[u].emplace_back(v, w);
  }

  int shortestPath(int node1, int node2) {
    vector<int> dis(n, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> hp;  // 小根堆
    dis[node1] = 0;
    hp.emplace(0, node1);
    while (!hp.empty()) {
      auto [d, u] = hp.top();
      hp.pop();
      if (u == node2) {
        return dis[u];
      }
      for (const auto& [nx, w] : g[u]) {
        if (dis[nx] > dis[u] + w) {
          dis[nx] = dis[u] + w;
          hp.emplace(dis[nx], nx);
        }
      }
    }
    return dis[node2] == INT_MAX ? -1 : dis[node2];
  }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
int main() {

  Solution test;
  return 0;
}
