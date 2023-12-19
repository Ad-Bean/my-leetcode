#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
一个 2D 网格中的 峰值 是指那些 严格大于 其相邻格子(上、下、左、右)的元素。

给你一个 从 0 开始编号 的 m x n 矩阵 mat ，其中任意两个相邻格子的值都 不相同 。找出 任意一个 峰值 mat[i][j] 并 返回其位置 [i,j] 。

你可以假设整个矩阵周边环绕着一圈值为 -1 的格子。

要求必须写出时间复杂度为 O(m log(n)) 或 O(n log(m)) 的算法

方法一：二分查找

类似 162 二分找峰值
如果某一行最大值比下面相邻数字小，则后面的行必有峰值
如果大，则前面的行就可能存在峰值

备注：一直往高处走
 */
class Solution {
 public:
  vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    int l = 0, r = mat.size() - 1;
    while (l <= r) {
      int i = l + (r - l) / 2;
      int row_max_idx = max_element(mat[i].begin(), mat[i].end()) - mat[i].begin();
      if (i + 1 < m && mat[i][row_max_idx] < mat[i + 1][row_max_idx]) {
        l = i + 1;
      } else if (i - 1 >= 0 && mat[i][row_max_idx] < mat[i - 1][row_max_idx]) {
        r = i - 1;
      } else {
        return vector<int>{i, row_max_idx};
      }
    }
    return {r, r};
  }
};
int main() {

  Solution test;
  return 0;
}
