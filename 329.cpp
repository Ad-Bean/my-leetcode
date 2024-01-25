/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 *
 * https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/description/
 *
 *
 * 给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。
 * 
 * 对于每个单元格，你可以往上，下，左，右四个方向移动。 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。
 * 
 * 
 * 
 * 输入：matrix = [[9,9,4],[6,6,8],[2,1,1]]
 * 输出：4 
 * 解释：最长递增路径为 [1, 2, 6, 9]。
 * 
 * 
 * 输入：matrix = [[3,4,5],[3,2,6],[2,2,1]]
 * 输出：4 
 * 解释：最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
 * 
 * 
 * 输入：matrix = [[1]]
 * 输出：1
 * 
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 200
 * 0 <= matrix[i][j] <= 2^31 - 1
 * 
 * 方法一：dfs 
 * 从每个点开始 dfs，此时时间复杂度是 n^n 级别，还会遇到搜过的路径，所以使用记忆化搜索
 * 比如 memo[i][j] != 0 即搜索过，直接读取结果
 * memo[i][j] 记录结果
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution {
 public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> memo(m, vector<int>(n));  //

    function<int(int, int)> dfs = [&](int r, int c) -> int {
      if (memo[r][c]) {
        return memo[r][c];
      }
      memo[r][c]++;
      for (const auto& dir : dirs) {
        int nx = r + dir[0], ny = c + dir[1];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
          if (matrix[nx][ny] > matrix[r][c]) {
            memo[r][c] = max(memo[r][c], dfs(nx, ny) + 1);
          }
        }
      }
      return memo[r][c];
    };

    int ans = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        ans = max(dfs(i, j), ans);
      }
    }
    return ans;
  }
};
// @lc code=end
