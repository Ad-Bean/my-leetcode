
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
有一些球形气球贴在一堵用 XY 平面表示的墙面上。
墙面上的气球记录在整数数组 points ，其中 points[i] = [xstart, xend] 
表示水平直径在 xstart 和 xend 之间的气球。你不知道气球的确切 y 坐标。

一支弓箭可以沿着 x 轴从不同点 完全垂直 地射出。
在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend，
且满足  xstart ≤ x ≤ xend，则该气球会被 引爆 。
可以射出的弓箭的数量 没有限制 。 
弓箭一旦被射出之后，可以无限地前进。

给你一个数组 points ，返回引爆所有气球所必须射出的 最小 弓箭数 。

输入：points = [[10,16],[2,8],[1,6],[7,12]]
输出：2
解释：气球可以用2支箭来爆破:
-在 x = 6 处射出箭，击破气球 [2,8] 和 [1,6]。
-在 x = 11 处发射箭，击破气球 [10,16] 和 [7,12]。

方法一：排序 + 贪心
对原数组排序，按照右端点排序！！
1 <= points.length <= 1e5
为什么是右端点排序？
因为一支箭可以引爆多个气球，贪心的思想就是让发射坐标尽可能靠右，涵盖更多坐标

 */
class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), [&](const auto& a, const auto& b) { return a[0] < b[0]; });
    int n = points.size();
    int cur = points[0][1];
    int ans = 1;
    for (int i = 1; i < n; i++) {
      if (points[i][0] <= cur) {
        // do nothing
      } else {
        ans++;
        cur = points[i][1];
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
  cout << test.findMinArrowShots(points) << endl;
  return 0;
}