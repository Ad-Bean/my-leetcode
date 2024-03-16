#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
2684. 矩阵中移动的最大次数
给你一个下标从 0 开始、大小为 m x n 的矩阵 grid ，矩阵由若干 正 整数组成。

你可以从矩阵第一列中的 任一 单元格出发，按以下方式遍历 grid ：

从单元格 (row, col) 可以移动到 (row - 1, col + 1)、(row, col + 1) 和 (row + 1, col + 1) 
向右，右下，右上
三个单元格中任一满足值 严格 大于当前单元格的单元格。
返回你在矩阵中能够 移动 的 最大 次数。


方法一：DFS
在二维矩阵中找一个最长的单调递增路径
一维的最长单调路径用动态规划可以解决或贪心二分
暴力：遍历第一列每一个起点，然后向右上下三个方向找最大的，然后继续爆搜下去

如果每列向右都单调递增，实际上最大值就是列的长度
但可能会遇到重复的点，假设从第一列下一行开始，走到了上次的路径，实际上答案是一样的，可以省去、剪枝

m, n <= 1000
时间复杂度 O(m * n)

方法二：BFS
将第一列入队，然后队每一层，如果能到下一列，入队之前没入队的点，用 vis 记录

空间优化：grid[i][j] > 0 所以队即将入队的店，改成相反数，省去 vis

 */
class Solution {
 public:
  int maxMoves(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int ans = 0;
    function<void(int, int)> dfs = [&](int x, int y) {
      ans = max(ans, y);
      if (ans == n - 1) {
        return;
      }
      for (int i = -1; i <= 1; i++) {
        int nx = x + i, ny = y + 1;
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > grid[x][y]) {
          dfs(nx, ny);
        }
        grid[x][y] = -1;  // 1 <= grid[i][j] <= 1e6
      }
    };
    for (int i = 0; i < m; i++) {
      dfs(i, 0);
    }
    return ans;
  }
};

int main() {

  Solution test;
  vector<vector<int>> grid = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9},
  };
  cout << test.maxMoves(grid) << endl;
  vector<vector<int>> grid2 = {
      {2, 3, 4, 5},
      {5, 4, 9, 3},
      {3, 4, 2, 11},
      {10, 9, 13, 15},
  };
  cout << test.maxMoves(grid2) << endl;
  vector<vector<int>> grid3 = {
      {3, 2, 4},
      {2, 1, 9},
      {1, 1, 7},
  };
  cout << test.maxMoves(grid3) << endl;
  return 0;
}
