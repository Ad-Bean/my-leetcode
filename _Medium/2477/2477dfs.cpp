
#include <bits/stdc++.h>
using namespace std;

/* 
输入：roads = [[0,1],[0,2],[0,3]], seats = 5
输出：3

输入：roads = [[3,1],[3,2],[1,0],[0,4],[0,5],[4,6]], seats = 2
输出：7

方法一：直观 BFS + 贪心
方法二：贡献法 + DFS + 贪心
根节点为 0 的树，所有结点向 根节点 0 移动，
对某个节点 x，父节点 y，让所有人从 x 坐车向上移动，需要 ceil(cnt[x] / seats) 辆车
从根节点向下 DFS，
统计 0 以外的每颗子树大小，累加 ceil(子树大小 / seats) 就是答案

向上取整技巧： ceil(a / b) = (a + b - 1) / b;

 */
class Solution {
  typedef long long ll;

 public:
  Solution() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
  }

  long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    int n = roads.size();
    vector<vector<int>> g(n + 1);
    for (const auto& road : roads) {
      int u = road[0], v = road[1];
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    ll ans = 0;
    function<int(int, int)> dfs = [&](int cur, int fa) -> int {
      int ppl = 1;
      for (const auto& nx : g[cur]) {
        if (nx != fa) {
          int pplNxt = dfs(nx, cur);
          ppl += pplNxt;
          ans += (pplNxt + seats - 1) / seats;
        }
      }
      return ppl;
    };
    dfs(0, -1);
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