#include <bits/stdc++.h>
using namespace std;

/* 
你在一个城市里，城市由 n 个路口组成，路口编号为 0 到 n - 1 ，某些路口之间有 双向 道路。输入保证你可以从任意路口出发到达其他任意路口，且任意两个路口之间最多有一条路。

给你一个整数 n 和二维整数数组 roads ，其中 roads[i] = [ui, vi, timei] 表示在路口 ui 和 vi 之间有一条需要花费 timei 时间才能通过的道路。你想知道花费 最少时间 从路口 0 出发到达路口 n - 1 的方案数。

请返回花费 最少时间 到达目的地的 路径数目 。由于答案可能很大，将结果对 1e9 + 7 取余 后返回。

输入：n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
输出：4
解释：从路口 0 出发到路口 6 花费的最少时间是 7 分钟。
四条花费 7 分钟的路径分别为：
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6

方法一：最短路
Dijkstra 求正权最短路，为了求出最短路径的数量，需要一个新的数组 cnt[i] 表示起点到 i 的最短路径数量
长度为 dis[i]。cnt[i] 更新方法和 dijkstra 更新 dis[i] 一样

为什么可以不用 vis


 */

class Solution {
 public:
  typedef pair<int, int> pii;
  using ll = long long;

  int countPaths(int n, vector<vector<int>>& roads) {
    const ll mod = 1e9 + 7;
    vector<vector<pii>> e(n);
    for (const auto& road : roads) {
      int u = road[0], v = road[1], w = road[2];
      e[u].emplace_back(v, w);
      e[v].emplace_back(u, w);
    }
    vector<ll> dis(n, LLONG_MAX);  // dis[i] 表示起点到 i 的最短路径长度
    vector<ll> cnt(n);             // cnt[i] 表示起点到 i 的最短路径数量

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> hp;
    // 最小堆，first 表示 dis[i]，second 表示 i
    hp.emplace(0, 0);
    dis[0] = 0;
    cnt[0] = 1;
    while (!hp.empty()) {
      auto [t, u] = hp.top();                // t 表示起点到 u 的最短路径长度, u 表示结点编号
      hp.pop();                              //
      if (t > dis[u]) {                      // 表示已经找到了最短路径
        continue;                            //
      }                                      //
      for (auto& [v, w] : e[u]) {            //
        if (t + w < dis[v]) {                // 松弛
          dis[v] = t + w;                    //
          cnt[v] = cnt[u];                   //
          hp.emplace(dis[v], v);             //
        } else if (t + w == dis[v]) {        //
          cnt[v] = (cnt[v] + cnt[u]) % mod;  // 和之前距离一样，路径数量相加
        }
      }
    }
    return cnt[n - 1];
  }
};
int main() {

  Solution test;
  return 0;
}
