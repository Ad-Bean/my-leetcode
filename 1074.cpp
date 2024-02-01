/*
 * @lc app=leetcode.cn id=1074 lang=cpp
 *
 * [1074] 元素和为目标值的子矩阵数量
 *
 * https://leetcode.cn/problems/number-of-submatrices-that-sum-to-target/description/
 *
 *
 * 给出矩阵 matrix 和目标值 target，返回元素总和等于目标值的非空子矩阵的数量。
 * 
 * 子矩阵 x1, y1, x2, y2 是满足 x1  且 y1  的所有单元 matrix[x][y] 的集合。
 * 
 * 如果 (x1, y1, x2, y2) 和 (x1', y1', x2', y2') 两个子矩阵中部分坐标不同（如：x1 !=
 * x1'），那么这两个子矩阵也不同。
 * 
 * 
 * 输入：matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
 * 输出：4
 * 解释：四个只含 0 的 1x1 子矩阵。
 * 
 * 
 * 
 * 输入：matrix = [[1,-1],[-1,1]], target = 0
 * 输出：5
 * 解释：两个 1x2 子矩阵，加上两个 2x1 子矩阵，再加上一个 2x2 子矩阵。
 * 
 * 
 * 输入：matrix = [[904]], target = 0
 * 输出：0
 * 
 * 1 <= matrix.length <= 100
 * 1 <= matrix[0].length <= 100
 * -1000 <= matrix[i] <= 1000
 * -10^8 <= target <= 10^8
 * 
 * 暴力：枚举所有矩阵左上角和右下角 + 哈希 Om^2 * n^2 
 * 
 * 方法一：前缀和 + 哈希 Om^2*n
 * 子矩阵的和，使用二位前缀和进行预处理:  sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
 * 找 target 的和，即 A+B 使用哈希
 * 
 * 有了二维前缀和后，O(n^2 * m^2) 10^8 枚举左上角和右下角 matrix[i][j] -> matrix[k][l] 可能超时
 * 可以从边来确定一个子矩阵即 长 a 宽 b，即三点 i 和 ii 控制宽度，j 控制长度
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
// @lc code=start
class Solution {
 public:
  int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> sum(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int ii = i; ii <= n; ii++) {
        unordered_map<int, int> mp;
        int cur = 0;
        for (int j = 1; j <= m; j++) {
          cur = sum[ii][j] - sum[i - 1][j];  // 右下角 ii,j 左上角 i,j
          if (cur == target) {               // 大矩阵
            ans++;                           //
          }                                  //
          if (mp.count(cur - target)) {      // 哈希表找第四条边
            ans += mp[cur - target];
          }
          mp[cur]++;
        }
      }
    }
    return ans;
  }
};
// @lc code=end
