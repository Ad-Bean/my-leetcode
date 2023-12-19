
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

/*
 图像平滑器 是大小为 3 x 3 的过滤器，用于对图像的每个单元格平滑处理，平滑处理后单元格的值为该单元格的平均灰度。

每个单元格的  平均灰度 定义为：该单元格自身及其周围的 8 个单元格的平均值，结果需向下取整。（即，需要计算蓝色平滑器中 9 个单元格的平均值）。

如果一个单元格周围存在单元格缺失的情况，则计算平均灰度时不考虑缺失的单元格（即，需要计算红色平滑器中 4 个单元格的平均值）。

方法一：模拟 + 二维前缀和优化

 */
class Solution {
 public:
  vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    int m = img.size(), n = img[0].size();
    vector<vector<int>> pre(m + 1, vector<int>(n + 1));

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + img[i - 1][j - 1];
      }
    }
    vector<vector<int>> ans(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int a = max(0, i - 1), b = max(0, j - 1);          // prev row, prev col
        int c = min(i + 1, m - 1), d = min(j + 1, n - 1);  // next row, next col
        int cnt = (c - a + 1) * (d - b + 1);
        int sum = pre[c + 1][d + 1] - pre[a][d + 1] - pre[c + 1][b] + pre[a][b];
        ans[i][j] = sum / cnt;
      }
    }
    return ans;
  }
};

/*  b     d

a  


c        


 */
int main() {

  Solution test;
  return 0;
}