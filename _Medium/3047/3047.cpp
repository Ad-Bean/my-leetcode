#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 

在二维平面上存在 n 个矩形。
给你两个下标从 0 开始的二维整数数组 bottomLeft 和 topRight，两个数组的大小都是 n x 2 ，
其中 bottomLeft[i] 和 topRight[i] 分别代表第 i 个矩形的 左下角 和 右上角 坐标。

我们定义 向右 的方向为 x 轴正半轴（x 坐标增加），向左 的方向为 x 轴负半轴（x 坐标减少）。
同样地，定义 向上 的方向为 y 轴正半轴（y 坐标增加），向下 的方向为 y 轴负半轴（y 坐标减少）。

你可以选择一个区域，该区域由两个矩形的 交集 形成。
你需要找出能够放入该区域 内 的 最大 正方形面积，并选择最优解。

返回能够放入交集区域的正方形的 最大 可能面积，如果矩形之间不存在任何交集区域，则返回 0。

方法一：枚举
如果两个矩形 bl0, tr0 和 bl1, tr1 有交集
则交集位置
左下 x: max(bl0[0], bl1[0])
左下 y: max(bl0[1], bl1[1])
右上 x: min(tr0[0], tr1[0])
右上 y: min(tr0[1], tr1[1])

所以 O(n^2) 枚举所有矩形的交集位置
找到最大的正方形面积

 */
class Solution {
 public:
  long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
    long long ans = 0;
    int n = bottomLeft.size();
    for (int i = 0; i < n; i++) {
      auto& bl0 = bottomLeft[i];  // reference to avoid timeout
      auto& tr0 = topRight[i];
      for (int j = i + 1; j < n; j++) {
        auto& bl1 = bottomLeft[j];
        auto& tr1 = topRight[j];
        int lx = max(bl0[0], bl1[0]);
        int ly = max(bl0[1], bl1[1]);
        int rx = min(tr0[0], tr1[0]);
        int ry = min(tr0[1], tr1[1]);
        int sq = min(ry - ly, rx - lx);
        if (sq > 0) {
          ans = max(ans, (long long)sq * sq);
        }
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}
