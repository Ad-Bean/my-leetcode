#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 

给你一个 n x n 的 方形 整数数组 matrix ，请你找出并返回通过 matrix 的下降路径 的 最小和 。

下降路径 可以从第一行中的任何元素开始，并从每一行中选择一个元素。
在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第一个元素）。具体来说，位置 (row, col) 的下一个元素应当是 (row + 1, col - 1)、(row + 1, col) 或者 (row + 1, col + 1) 。

方法一：DP

 */
class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n + 2, 0x3f3f3f3f));
    for (int i = 0; i < n; i++) {
      dp[0][i + 1] = matrix[0][i];  // 第一行开始
    }
    for (int r = 1; r < n; r++) {
      for (int c = 0; c < n; c++) {
        dp[r][c + 1] = min(min(dp[r - 1][c], dp[r - 1][c + 1]), dp[r - 1][c + 2]) + matrix[r][c];
      }
    }
    return *min_element(dp[n - 1].begin(), dp[n - 1].end());
  }
};
int main() {

  Solution test;
  return 0;
}
