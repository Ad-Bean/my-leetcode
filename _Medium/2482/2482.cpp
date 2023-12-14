#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 

给你一个下标从 0 开始的 m x n **二进制矩阵** grid 。

我们按照如下过程，定义一个下标从 0 开始的 m x n 差值矩阵 diff ：

令第 i 行一的数目为 onesRowi 。
令第 j 列一的数目为 onesColj 。
令第 i 行零的数目为 zerosRowi 。
令第 j 列零的数目为 zerosColj 。
diff[i][j] = onesRowi + onesColj - (zerosRowi + zerosColj)
请你返回差值矩阵 diff 。

grid           diff 
[0,1,1]       [0,0,4]                 
[1,0,1]       [1,0,1]             
[0,0,1]       [0,0,1]             

onesRowi  = [2,2,1]
onesColj  = [1,1,3]
zerosRowi = [1,1,2] -> m - onesRow
zerosColj = [2,2,0] -> n - onesCol


onesRowi + onesColj - (zerosRowi + zerosColj) == 2 * onesRow + 2 * onesCol - m - n
方法一：模拟

记录 ones[i][j]
 */
class Solution {
 public:
  vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> r(m), c(n);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          r[i]++, c[j]++;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        grid[i][j] = 2 * r[i] + 2 * c[j] - m - n;
      }
    }
    return grid;
  }
};
int main() {

  Solution test;
  return 0;
}