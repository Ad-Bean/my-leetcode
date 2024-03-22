#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
给你一个下标从 0 开始的 m x n 整数矩阵 grid 。你一开始的位置在 左上角 格子 (0, 0) 。

当你在格子 (i, j) 的时候，你可以移动到以下格子之一：

满足 j < k <= grid[i][j] + j 的格子 (i, k) （向右移动），或者
满足 i < k <= grid[i][j] + i 的格子 (k, j) （向下移动）。
请你返回到达 右下角 格子 (m - 1, n - 1) 需要经过的最少移动格子数，如果无法到达右下角格子，请你返回 -1 。

1 <= m, n <= 10^5

输入：grid = [
    [3,4,2,1],
    [4,2,3,1],
    [2,1,0,0],
    [2,4,0,0],
    ]
输出：4
解释：上图展示了到达右下角格子经过的 4 个格子。

方法一：
向右走 or 向下走 不超过当前格子的值
为了到达右下角，一般用 BFS 找最短路径
比如先将起点入队，将所有可以到达的点（从远到近）入队，直到 (m-1, n-1) 见到则返回 
但是有几个问题：向右最远的并不一定能够抵达右下角

反转思路，用两个 set 或者优先队列/堆记录所有还没到达的行和列 row[n] 和 col[m]
用队列 BFS，入队当前 0,0
每次取出队首，
1. 在 row[i] 中找到第一个比 j 大的位置，然后如果这个位置在 j + grid[i][j] 内，入队
   更新 f[i][*it] = f[i][j] + 1 表示到达这个位置的最少步数
   删除这个位置 it = row[i].earse(it) 并且继续往右走
   在 col[*it] 中删除 i
2. 在 col[j] 中找到第一个比 i 大的位置，如果这个位置在 i + grid[i][j] 内，入队
   更新 f[*it][j] = f[i][j] + 1
   删除这个位置 it = col[j].earse(it) 并且继续往下走
   在 row[*it] 中删除 j

删除表示这个位置已经到达过了
为什么用 set / priority_queue
1. 保证每个点只会入队一次
2. log 时间复杂度找到第一个大于当前并且还没到过的位置，判断是否能到达


 */
class Solution {
  typedef pair<int, int> pii;

 public:
  int minimumVisitedCells(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    set<int> r[n], c[m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i + j > 0) {
          r[i].insert(j);  // row[i]
          c[j].insert(i);  // col[j]
        }
      }
    }
    int f[n][m];
    memset(f, -1, sizeof(f));
    queue<pii> q;
    q.push({0, 0});
    f[0][0] = 1;
    while (!q.empty()) {
      auto [i, j] = q.front();        //  不要用引用，否则可能会访问已经释放的内存
      q.pop();                        //
      auto it = r[i].upper_bound(j);  // 在 row[i] 中找到第一个大于 j 的元素
      while (it != r[i].end()) {      //
        if (*it > j + grid[i][j]) {   // 无法抵达
          break;                      //
        }
        q.push({i, *it});
        f[i][*it] = f[i][j] + 1;
        c[*it].erase(i);
        it = r[i].erase(it);
      }
      it = c[j].upper_bound(i);      // 在 col[j] 中找到第一个大于 i 的元素
      while (it != c[j].end()) {     //
        if (*it > i + grid[i][j]) {  // 无法抵达
          break;                     //
        }                            //
        q.push({*it, j});            // 向下
        f[*it][j] = f[i][j] + 1;     //
        r[*it].erase(j);             //
        it = c[j].erase(it);         //
      }
    }
    return f[n - 1][m - 1];
  }
};
int main() {

  Solution test;
  return 0;
}
