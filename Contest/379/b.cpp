#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
现有一个下标从 0 开始的 8 x 8 棋盘，上面有 3 枚棋子。

给你 6 个整数 a 、b 、c 、d 、e 和 f ，其中：

(a, b) 表示白色车的位置。
(c, d) 表示白色象的位置。
(e, f) 表示黑皇后的位置。
假定你只能移动白色棋子，返回捕获黑皇后所需的最少移动次数。

请注意：

车可以向垂直或水平方向移动任意数量的格子，但不能跳过其他棋子。
象可以沿对角线方向移动任意数量的格子，但不能跳过其他棋子。
如果车或象能移向皇后所在的格子，则认为它们可以捕获皇后。
皇后不能移动。

方法一：分类讨论

1. 白车可以直接攻击黑后
2. 白象可以直接攻击黑后
3. 闪击：车被象挡，移走象，车直接攻击黑后
4. 闪击：象被车挡，移走车，象直接攻击黑后
5. 其他情况：移动车

可以用向量判断三点关系
判断向量AB和向量AC的斜率是否相等。即 (y2 - y1)/(x2 - x1) == (y3 - y1)/(x3 - x1).
防止除数为零的问题可以把这个判断转成乘法：(y3 - y1) * (x2 - x1) - (y2 - y1) * (x3 - x1)==0
 */
class Solution {
 public:
  int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
    int cnt_a = 0;
    if (a == e && b == f) {
      cnt_a = 0;
    } else if (a == e || b == f) {
      // 象是否在车的路径上，向右向左向下向上挡住
      if (((a == c && a == e) && ((b < d && d < f) || (f < d && d < b))) ||
          ((b == d && b == f) && ((e < c && c < a) || (a < c && c < e)))) {
        cnt_a = 2;
      } else {
        cnt_a = 1;
      }
    } else {
      cnt_a = 2;
    }

    int cnt_b = 0;
    if (c == e) {
      cnt_b = 2;
    } else if (abs(1.0 * (f - d) / (e - c)) == 1.0) {
      // 车是否在象到皇的路线上
      if (e != a && (f - d) / (e - c) == (f - b) / (e - a)) {
        if (((c < a && a < e) && (d < b && b < f)) || ((e < a && a < c) && (f < b && b < d)) ||
            ((c < a && a < e) && (f < b && b < d)) || ((e < a && a < c) && (d < b && b < f))) {
          cnt_b = 3;
        } else {
          cnt_b = 1;
        }
      } else {
        cnt_b = 1;
      }
    } else {
      cnt_b = 2;
    }
    return min(cnt_a, cnt_b);
  }
};
int main() {

  Solution test;
  //   cout << test.minMovesToCaptureTheQueen(4, 3, 3, 4, 2, 5) << endl;
  //   cout << test.minMovesToCaptureTheQueen(4, 3, 3, 4, 5, 2) << endl;
  //   cout << test.minMovesToCaptureTheQueen(4, 5, 6, 8, 2, 1) << endl;
  cout << test.minMovesToCaptureTheQueen(7, 4, 7, 5, 7, 3) << endl;
  return 0;
}