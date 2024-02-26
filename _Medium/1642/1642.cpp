#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个整数数组 heights ，表示建筑物的高度。另有一些砖块 bricks 和梯子 ladders 。

你从建筑物 0 开始旅程，不断向后面的建筑物移动，期间可能会用到砖块或梯子。

当从建筑物 i 移动到建筑物 i+1（下标 从 0 开始 ）时：

如果当前建筑物的高度 大于或等于 下一建筑物的高度，则不需要梯子或砖块
如果当前建筑的高度 小于 下一个建筑的高度，您可以使用 一架梯子 或 (h[i+1] - h[i]) 个砖块
如果以最佳方式使用给定的梯子和砖块，返回你可以到达的  最远建筑物  的下标（下标 从 0 开始 ）。

输入：heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
输出：4
解释：从建筑物 0 出发，你可以按此方案完成旅程：
- 不使用砖块或梯子到达建筑物 1 ，因为 4 >= 2
- 使用 5 个砖块到达建筑物 2 。你必须使用砖块或梯子，因为 2 < 7
- 不使用砖块或梯子到达建筑物 3 ，因为 7 >= 6
- 使用唯一的梯子到达建筑物 4 。你必须使用砖块或梯子，因为 6 < 9
无法越过建筑物 4 ，因为没有更多砖块或梯子。

方法一：贪心
为了走到最远的建筑，需要在 dif 最大的时候用梯子
所以使用梯子的地方就是 dif 最大的几个地方
用一个优先队列维护 dif，如果数量大于梯子数量，则弹出最小的一个，用砖块
 */
class Solution {
 public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    int n = heights.size();
    priority_queue<int, vector<int>, greater<int>> hp;
    for (int i = 1; i < n; i++) {
      int dif = heights[i] - heights[i - 1];
      if (dif > 0) {
        hp.emplace(dif);
        if (hp.size() > ladders) {
          bricks -= hp.top();
          hp.pop();
          if (bricks < 0) {
            return i - 1;
          }
        }
      }
    }
    return n - 1;
  }
};
int main() {

  Solution test;
  return 0;
}
