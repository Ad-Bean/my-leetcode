
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个大小为 m x n 的网格和一个球。球的起始坐标为 [startRow, startColumn] 。
你可以将球移到在四个方向上相邻的单元格内（可以穿过网格边界到达网格之外）。
你 最多 可以移动 maxMove 次球。

给你五个整数 m、n、maxMove、startRow 以及 startColumn ，找出并返回可以将球移出边界的路径数量。
因为答案可能非常大，返回对 1e9 + 7 取余 后的结果。


方法一：记忆化搜索
对于本题，是四联通，非单向，有环。所以会遇到重复的路径，使用记忆化搜索

记忆化搜索 DFS
int dfs(int x, int y, int k) {}
x,y 点，移动了 k 步

递归出口：棋盘外 or 剩余步数为 0

int cache[m][n][maxMove + 1];
function<int(int, int, int)> dfs = [&](int x, int y, int k) -> int {
    if (x < 0 || x >= m || y < 0 || y >= n) {
    return 1;
    }
    if (k == 0) {
    return 0;
    }
    if (cache[x][y][k] != -1) {
    return cache[x][y][k];
    }
    int ans = 0;
    for (const auto d : dirs) {
    int nx = x + d[0], ny = y + d[1];
    ans += dfs(nx, ny, k - 1);
    ans %= MOD;
    }
    cache[x][y][k] = ans;
    return ans;
};

方法二：动态规划
DP 路径问题
因为记忆化搜索确保了每个状态只访问一次，它也是一种常见的动态规划实现方式。
状态无后效性：对某个状态，不需要关注状态是如何转移过来的
数据范围：1e5 - 1e6 一维 dp  1e2 - 1e3 二维 dp
求方案数

从记忆化搜索，可以假设 f[m*n][k] 为 dp 数组
f[x,y][step] = f[x-1,y][step - 1] + f[x+1,y][step - 1] + f[x,y+1][step - 1] + f[x,y-1][step - 1]
f[i][j] 依赖于 f[x][j-1] 所以最大移动步数 从小到大 开始枚举

在边缘时，只需要一步就可以走出去，从边界开始推
考虑初始化 dp 数组并开始滚动
边缘位置 f[0,0:m-1][k] 只需要一步
边缘位置 f[n-1,0:m-1][k] 只需要一步
边缘位置 f[0:n-1,0][k] 只需要一步
边缘位置 f[0:n-1,m-1][k] 只需要一步
所以当 k >= 1 的时候，方案数都 + 1

从 k = 1 到 maxMove 开始枚举所有的位置，如果这个位置能够往四周扩散（下一个位置能够通过 k - 1 到达这里）


动态规划的实现，本质是将问题进行反向：
原问题是让我们求从棋盘的特定位置出发，出界的路径数量。
实现时，我们则是从边缘在状态出发，逐步推导回起点的出界路径数量为多少。
 */

const int MOD = 1e9 + 7;
int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
class Solution {
 public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    // dp[idx][k] 表示坐标 idx 有 maxMove 时走出边界的路径数量
    int dp[m * n][maxMove + 1];
    function<vector<int>(int)> getIdx = [&](int idx) {
      return vector<int>{idx / n, idx % n};
    };
    memset(dp, 0, sizeof(dp));

    // 初始化，表示在边界 i * n + j，还剩 k 步时 有几种方案走出
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0) {
          for (int k = 1; k <= maxMove; k++) {
            dp[i * n + j][k]++;
          }
        }
        if (i == m - 1) {
          for (int k = 1; k <= maxMove; k++) {
            dp[i * n + j][k]++;
          }
        }
        if (j == 0) {
          for (int k = 1; k <= maxMove; k++) {
            dp[i * n + j][k]++;
          }
        }
        if (j == n - 1) {
          for (int k = 1; k <= maxMove; k++) {
            dp[i * n + j][k]++;
          }
        }
      }
    }
    // 从小到大枚举步数
    for (int k = 1; k <= maxMove; k++) {
      for (int idx = 0; idx < m * n; idx++) {
        auto xy = getIdx(idx);                           // 当前位置
        for (const auto& dir : dirs) {                   //
          int nx = dir[0] + xy[0], ny = dir[1] + xy[1];  // 下一个位置
          if (nx >= 0 && nx < m && ny >= 0 && ny < n) {  //
            dp[idx][k] += dp[nx * n + ny][k - 1];        // 当前位置 由下一个位置减一步
            dp[idx][k] %= MOD;
          }
        }
      }
    }
    return dp[startRow * n + startColumn][maxMove];
  }
};
int main() {

  Solution test;
  cout << test.findPaths(2, 2, 2, 0, 0) << endl;
  return 0;
}