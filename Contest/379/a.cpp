#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

/* 
给你一个下标从 0 开始的二维整数数组 dimensions。

对于所有下标 i（0 <= i < dimensions.length），dimensions[i][0] 表示矩形 i 的长度，而 dimensions[i][1] 表示矩形 i 的宽度。

返回对角线最 长 的矩形的 面积 。如果存在多个对角线长度相同的矩形，返回面积最 大 的矩形的面积。


方法一：遍历
一些细节：不需要开根号，使用 a^2 + b^2 
 */
class Solution {
 public:
  int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
    int dia = 0;
    int area = 0;
    for (const auto d : dimensions) {
      int a = d[0], b = d[1];
      int dd = (a * a + b * b);
      if (dd > dia || (dd == dia && a * b > area)) {
        dia = dd;
        area = a * b;
      }
    }
    return area;
  }
};
int main() {

  Solution test;
  vector<vector<int>> dimensions = {{6, 5}, {8, 6}, {2, 10}, {8, 1}, {9, 2}, {3, 5}, {3, 5}};
  cout << test.areaOfMaxDiagonal(dimensions) << endl;
  return 0;
}