#include <bits/stdc++.h>
using namespace std;
/* 
0,0 -> rows-1, cols-1
消耗体力的最小值

一条路径的体力值是相邻格子间高度差绝对值的最大值

r,c <= 100
方法一：暴力所有解法取最小最大，2^100 必然超时
方法二：贪心
如果贪心，很明显有反例

方法三：二分查找
最小最大，可以使用二分答案方法，在 [0, INT_MAX or 1e6] 中遍历，
check 从左上角开始 dfs/bfs 只走 dif <= mid 的路，没有则返回 false
时间复杂度 O(mnlogC) C 其实可以通过找到最大值减少而不是固定 1e6

方法二：图论 Kurskal + 并查集
为什么不是 DP，因为可以任意方向移动，而 DP 是特殊图论问题，状态展开后不是拓扑排序
最短路/最小生成树/二分图匹配，总是用特定算法，但需要知道如何建图

对于本题，由于是在任意格子可以任意方向移动，所以相邻的格子存在无向边
于是题目转成，起点到终点，路径中的最小权重的 最大值 是多少
权重是两者高度差的绝对值

对集合按照权重从小到大排序，（Kruskal 最小生成树），使用并查集连接最小权重的边，直到 0 和 m * n - 1 联通
时间复杂度：O(mnlog⁡(mn))

方法三：图论 Dijkstra 最短路
Dijkstra 是求最短路，但本题求的是，经过边权的最大值

Dijkstra 本质是启发式搜索，启发函数 h = 0 时的特殊情况



 */
typedef pair<int, int> pii;

class Solution {
  int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

 public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    int m = heights.size(), n = heights[0].size();
    int l = 0, r = 1e6;
    int ans = 0;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      // check
      queue<int> q;
      q.emplace(0);
      vector<bool> vis(m * n);
      vis[0] = true;
      while (!q.empty()) {
        int cur = q.front();
        // x * n + y = cur
        int x = cur / n, y = cur % n;
        q.pop();
        for (int i = 0; i < 4; i++) {
          int nx = x + dirs[i][0], ny = y + dirs[i][1];
          if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
            if (!vis[nx * n + ny] && abs(heights[nx][ny] - heights[x][y]) <= mid) {
              q.emplace(nx * n + ny);
              vis[nx * n + ny] = true;
            }
          }
        }
      }
      if (vis[m * n - 1]) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return ans;
  }
};
int main() {
  vector<vector<int>> dirs = {{1, 2, 1, 1, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 1, 1, 2, 1}};
  Solution test;
  cout << test.minimumEffortPath(dirs) << endl;
  return 0;
}
