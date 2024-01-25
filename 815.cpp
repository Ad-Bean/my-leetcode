/*
 * @lc app=leetcode.cn id=815 lang=cpp
 *
 * [815] 公交路线
 *
 * https://leetcode.cn/problems/bus-routes/description/
 *
 * 给你一个数组 routes ，表示一系列公交线路，其中每个 routes[i] 表示一条公交线路，
 * 第 i 辆公交车将会在上面循环行驶。
 * 
 * 
 * 例如，路线 routes[0] = [1, 5, 7] 表示第 0 辆公交车会一直按序列 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1
 * -> ... 这样的车站路线行驶。
 * 
 * 
 * 现在从 source 车站出发（初始时不在公交车上），要前往 target 车站。 期间仅可乘坐公交车。
 * 
 * 求出 最少乘坐的公交车数量 。如果不可能到达终点车站，返回 -1 。
 * 
 * 
 * 输入：routes = [[1,2,7],[3,6,7]], source = 1, target = 6
 * 输出：2
 * 解释：最优策略是先乘坐第一辆公交车到达车站 7 , 然后换乘第二辆公交车到车站 6 。 
 * 
 * 
 * 输入：routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
 * 输出：-1
 * 
 * 
 * 1 <= routes.length <= 500.
 * 1 <= routes[i].length <= 10^5
 * routes[i] 中的所有值 互不相同
 * sum(routes[i].length) <= 10^5
 * 0 <= routes[i][j] < 10^6
 * 0 <= source, target < 10^6
 * 
 * 方法一：BFS
 * 由于需要求最短路，一般使用 Dijkstra, BFS
 * 建图，从 source 开始 bfs 直到 target
 * 
 * 但怎么知道坐了几辆公交车呢？
 * 所以结点应该是公交车，而结点内才是路线
 * 使用 g[x][y] 表示 x 公交车可以抵达 y 站点
 * 记录每个车站所属的公交车 route2bus[routes[i][j]] = {bus_i, bus_ii} // 一个站点有多个公交车 
 * for i in range(n):
 *   for route in routes[i]:
 *    for bus in route2bus:
 *       g[bus][i] = true
 *       g[i][route] = true 
 *    g[i].emplace_back(route)
 *   
 * 
 * 从 source 找到对应的公交车，可能有多个，入队后开始 BFS
 * 对于当前公交车 x 如果能到达某个站 y，即有边
 * 
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

// @lc code=start
class Solution {
 public:
  int numBusesToDestination(vector<vector<int>>& routes, int s, int t) {
    if (s == t) {
      return 0;
    }

    int n = routes.size();                           // # of buses
    vector<vector<int>> g(n, vector<int>(n));        // bus -> route
    unordered_map<int, vector<int>> route2bus;       // route -> buses
    for (int bus_i = 0; bus_i < n; bus_i++) {        // bus_i
      for (const int& route : routes[bus_i]) {       //
        for (const int& bus_j : route2bus[route]) {  //
          g[bus_i][bus_j] = true;                    // bus_i -> bus_j
          g[bus_j][bus_i] = true;                    // bus_i <- bus_j
        }                                            //
        route2bus[route].emplace_back(bus_i);        // buses that pass this route
      }
    }

    vector<int> dis(n, -1);
    queue<int> q;                         // stores buses
    for (const int bus : route2bus[s]) {  //
      q.emplace(bus);                     // all the buses that can start from s
      dis[bus] = 1;                       // initialize 1
    }

    while (!q.empty()) {
      int bus_i = q.front();                        // bus_i
      q.pop();                                      //
      for (int bus_j = 0; bus_j < n; bus_j++) {     //
        if (g[bus_i][bus_j] && dis[bus_j] == -1) {  //
          dis[bus_j] = dis[bus_i] + 1;
          q.emplace(bus_j);
        }
      }
    }
    int ans = INT_MAX;
    for (const int& bus : route2bus[t]) {
      if (dis[bus] != -1) {
        ans = min(ans, dis[bus]);  // the min # of buses
      }
    }
    return ans == INT_MAX ? -1 : ans;
  }
};
// @lc code=end

int main() {
  Solution test;
  vector<vector<int>> r = {{1, 2, 7}, {3, 6, 7}};
  int s = 1, t = 6;
  cout << test.numBusesToDestination(r, s, t) << endl;
}