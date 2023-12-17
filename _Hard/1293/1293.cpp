
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
给你一个 m * n 的网格，其中每个单元格不是 0（空）就是 1（障碍物）。

每一步，您都可以在空白单元格中上、下、左、右移动。

如果您 最多 可以消除 k 个障碍物，请找出从左上角 (0, 0) 到右下角 (m-1, n-1) 的最短路径，并返回通过该路径所需的步数。

如果找不到这样的路径，则返回 -1 。


方法一：BFS

因为可以消除障碍，所以需要在 BFS 时添加一个搜索状态 (x, y, z)
z 表示还可以经过多少个障碍物，必须 >= 0
向四个方向移动，如果是障碍物则 (x + dx, y+dy, z-1) 否则 (x+dx, y+dy, z)

BFS 时候层级，如果下一级非空则 cnt + 1

搜索空间优化： k 上限是 m * n 但是 0,0 到 m-1,n-1 最多也就 m+n-1 步

k 取 min(m+n-3, k) // 除掉 首尾

方法二：双向 BFS


 */
class Solution {
  typedef tuple<int, int, int> tpl;
  static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

 public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size();
    if (m == 1 && n == 1) {
      return 0;
    }
    if (k >= m + n - 2) {
      return m + n - 2;
    }
    k = min(m + n - 3, k);
    queue<tpl> que;  // x,y,z
    que.emplace(0, 0, k);
    vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(k + 1)));
    vis[0][0][k] = true;
    int cnt = 0;
    while (!que.empty()) {
      int sz = que.size();
      for (int i = 0; i < sz; i++) {
        auto [x, y, z] = que.front();  // 为什么这里不可以用引用？
        que.pop();
        for (const auto& dir : dirs) {
          int nx = dir[0] + x, ny = dir[1] + y;
          if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
            if (grid[nx][ny] == 0 && !vis[nx][ny][z]) {
              if (nx == m - 1 && ny == n - 1) {
                return cnt + 1;
              }
              que.emplace(nx, ny, z);
              vis[nx][ny][z] = true;

            } else if (grid[nx][ny] == 1 && z > 0 && !vis[nx][ny][z - 1]) {
              que.emplace(nx, ny, z - 1);
              vis[nx][ny][z - 1] = true;
            }
          }
        }
      }
      if (!que.empty()) {
        cnt++;
      }
    }
    return -1;
  }
};
int main() {
  vector<vector<int>> grid = {
      {0, 1, 0, 1}, {0, 1, 0, 0}, {0, 0, 1, 0}, {1, 0, 0, 1}, {0, 1, 0, 0},
  };
  int k = 18;
  Solution test;
  cout << test.shortestPath(grid, k) << endl;
  return 0;
}