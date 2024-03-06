#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

/* 
科技馆内有一台虚拟观景望远镜，它可以用来观测特定纬度地区的地形情况。该纬度的海拔数据记于数组 heights ，其中 heights[i] 表示对应位置的海拔高度。请找出并返回望远镜视野范围 limit 内，可以观测到的最高海拔值。

示例 1：

输入：heights = [14,2,27,-5,28,13,39], limit = 3
输出：[27,27,28,28,39]
解释：
  滑动窗口的位置                最大值
---------------               -----
[14 2 27] -5 28 13 39          27
14 [2 27 -5] 28 13 39          27
14 2 [27 -5 28] 13 39          28
14 2 27 [-5 28 13] 39          28
14 2 27 -5 [28 13 39]          39

方法一：堆 + 自定义排序函数
维护一个大小为 k 的大顶堆，存入下标，用自定义 compare 函数，将下标对应的值大的放在堆顶
每次窗口向右移动，如果堆顶的下标不在窗口内，就弹出堆顶
 */

class Solution {
 public:
  vector<int> maxAltitude(vector<int>& heights, int k) {
    auto cmp = [&](int a, int b) {
      return heights[a] < heights[b];
    };
    priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
    int n = heights.size();
    vector<int> ans;
    for (int i = 0; i < k; i++) {
      q.emplace(i);
    }
    ans.emplace_back(heights[q.top()]);

    for (int i = k; i < n; i++) {
      q.emplace(i);
      while (q.top() + k <= i) {  // 最大的值的下标 在当前窗口外
        q.pop();
      }
      ans.emplace_back(heights[q.top()]);
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}