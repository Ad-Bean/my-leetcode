
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，
用一个数组返回这个矩阵中的所有元素。

输入：mat = [
    [1,2,3],
    [4,5,6],
    [7,8,9]]
输出：[1,2,4,7,5,3,6,8,9]
idx: 00, 
     01 10, 
     20 11 02, 
     12 21,
     22
输入：mat = [
    [1,2,3],
    [4,5,6],
    [7,8,9],
    [7,8,9],
    [7,8,9],
    ]
idx: 00,          // i,0
     01 10,       //      
     20 11 02,    // i,0
     12 21 30,    //      i-(n-1), n-1
     40 31 22     // i,0
     32 41        //      i-(n-1), n-1
     42           // m - 1, i - (m - 1)


方法一：模拟
一共有 m + n - 1 条对角线，每次遍历方向不同
i 偶数，从下往上
i 奇数，从上往下

下往上，行 - 1，列 + 1
上往下，行 + 1，列 - 1
 */

class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<int> res;
    for (int i = 0; i < m + n - 1; i++) {
      if (i & 1) {
        int r = i < n ? 0 : i - (n - 1), c = i < n ? i : n - 1;
        while (r < m && c >= 0) {
          res.emplace_back(mat[r][c]);
          r++, c--;
        }
      } else {
        int r = i < m ? i : m - 1, c = i < m ? 0 : i - (m - 1);
        while (r >= 0 && c < n) {
          res.emplace_back(mat[r][c]);
          r--, c++;
        }
      }
    }
    return res;
  }
};
int main() {

  Solution test;
  return 0;
}