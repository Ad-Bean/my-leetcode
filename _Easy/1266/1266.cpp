
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
平面上有 n 个点，点的位置用整数坐标表示 points[i] = [xi, yi] 。请你计算访问所有这些点需要的 **最小时间**（以秒为单位）。

每一秒内，你可以：
沿水平方向移动一个单位长度，或者
沿竖直方向移动一个单位长度，或者
跨过对角线移动 sqrt(2) 个单位长度（可以看作在一秒内向水平和竖直方向各移动一个单位长度）。

dx < dy, 对角线移动 dx，竖直移动 dy - dx，共 dy
dx = dy，对角线移动 dx，                 共 dx
dx > dy，对角线移动 dy，水平移动 dx - dy，共 dx

所以如果 dy 大就加 dy， dx 大就加 dx
 */
class Solution {
 public:
  int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int ans = 0, n = points.size();
    int x = points[0][0], y = points[0][1];

    for (int i = 1; i < n; i++) {
      int nx = points[i][0], ny = points[i][1];
      ans += max(abs(x - nx), abs(y - ny));
      x = nx;
      y = ny;
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}