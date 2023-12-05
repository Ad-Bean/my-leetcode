
#include <bits/stdc++.h>
using namespace std;

/* 
输入：roads = [[0,1],[0,2],[0,3]], seats = 5
输出：3

输入：roads = [[3,1],[3,2],[1,0],[0,4],[0,5],[4,6]], seats = 2
输出：7

方法一：直观 BFS + 贪心
先用 BFS 确定每个节点到 0 根节点的距离，向上归并，用dis2n记录每个距离对应的节点的列表
从最远的层开始，对每个结点，贪心用最少的车：
当前节点有 num / seats 辆车，需要 num % seats 辆车，并且将人数 num 向内推给下一层 nums[nx] += nums[cur]

方法二：贡献法 + DFS + 贪心

 */
class Solution {
  typedef long long ll;

 public:
  long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    int n = roads.size();
    unordered_map<int, int> next_node;  // 不同层，由外向根连接 1 -> 0, 2->0, 3->0
    vector<vector<int>> g(n + 1);
    for (const auto& road : roads) {
      int u = road[0], v = road[1];
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    unordered_map<int, bool> vis;
    vector<vector<int>> levels;  // 记录每一层
    queue<int> q;
    q.emplace(0);
    vis[0] = true;
    int cur_dis = 0;
    levels.push_back({0});
    while (!q.empty()) {
      cur_dis++;
      int sz = q.size();
      // vector<int> cur_level;  // outer level loop, copy problem, need to use move
      for (int i = 0; i < sz; i++) {
        int cur = q.front();
        q.pop();
        vector<int> cur_level;  // inner level loop
        for (const int& nx : g[cur]) {
          if (!vis[nx]) {
            q.emplace(nx);
            vis[nx] = true;
            next_node[nx] = cur;
            cur_level.emplace_back(nx);
          }
        }
        levels.push_back(cur_level);  // inner level
        // cur_level.clear();                  // if cur_level is defined at outer level, please clear or move() to avoid copy
        // levels.push_back(move(cur_level));  // if cur_level is define at upper level
      }
    }
    ll ans = 0;
    vector<int> cur_num(n + 1, 1);  // 当前乘客数量
    // 从最外层开始，都是 1，向内递增，如果大于 seats 则需要多分一台车
    for (int i = levels.size() - 1; i >= 1; i--) {
      for (const int& cur : levels[i]) {
        ans += cur_num[cur] / seats;      // 需要有几辆车
        if (cur_num[cur] % seats != 0) {  // 为剩下的人分配车
          ans++;
        }
        // 链接 cur 并且向根的结点的要加上贡献
        int nx = next_node[cur];
        cur_num[nx] += cur_num[cur];
      }
    }
    return ans;
  }
};
int main() {
  vector<vector<int>> roads = {{3, 1}, {3, 2}, {1, 0}, {0, 4}, {0, 5}, {4, 6}};
  int seats = 2;
  Solution test;
  cout << test.minimumFuelCost(roads, seats) << endl;
  return 0;
}