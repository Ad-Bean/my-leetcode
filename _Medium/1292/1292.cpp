#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个大小为 m x n 的矩阵 mat 和一个整数阈值 threshold。

请你返回元素总和小于或等于阈值的正方形区域的 最大边长；如果没有这样的正方形区域，则返回 0 。

方法一：区间和 + 枚举
二位前缀和，然后枚举正方形，判断是否满足条件


二位前缀和 sum(i,j,x,y) = pre[x][y] - pre[i-1][y] - pre[x][j-1] + pre[i-1][j-1]
枚举正方形的边：O(MN*min(M,N))
优化枚举，第三重循环枚举的是正方形的边长：
由于元素和递增，如果此时边长 c 的元素和已经超过 threshold，那么 c+1 的元素和一定超过 threshold，跳过
因为是找最大的边长，从 i,j 开始又从 1 开始找不合理，直接从 ans 开始找
 */
class Solution {
 public:
  int maxSideLength(vector<vector<int>>& mat, int threshold) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> pre(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + mat[i - 1][j - 1];
      }
    }

    function<int(int, int, int, int)> getSum = [&](int x1, int y1, int x2, int y2) {
      return pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
    };

    int ans = 0;  //
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        for (int c = ans; c <= min(m, n); c++) {
          if (i + c - 1 <= m && j + c - 1 <= n && getSum(i, j, i + c - 1, j + c - 1) <= threshold) {
            ans++;
          } else {
            break;
          }
        }
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  vector<vector<int>> mat = {{2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}};
  cout << test.maxSideLength(mat, 1) << endl;
  return 0;
}
