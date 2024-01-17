#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给定两个由一些 闭区间 组成的列表，firstList 和 secondList ，其中 firstList[i] = [starti, endi] 而 secondList[j] = [startj, endj] 。每个区间列表都是成对 不相交 的，并且 已经排序 。

返回这 两个区间列表的交集 。

形式上，闭区间 [a, b]（其中 a <= b）表示实数 x 的集合，而 a <= x <= b 。

两个闭区间的 交集 是一组实数，要么为空集，要么为闭区间。例如，[1, 3] 和 [2, 4] 的交集为 [2, 3] 。

方法一：双指针
由于两个区间都已排序
用双指针遍历两个区间数组
对两个区间，求交集，找出左端点 max(l1, l2) 和 右端点 min(r1, r2)
如果区间1 在区间2 左边，则无法与后面的重叠，所以需要走到下一个区间

 */
class Solution {
 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
    vector<vector<int>> ans;
    int l = 0, r = 0;
    int n = firstList.size(), m = secondList.size();
    while (l < n && r < m) {
      int lo = max(firstList[l][0], secondList[r][0]);
      int hi = min(firstList[l][1], secondList[r][1]);
      if (lo <= hi) {
        ans.push_back({lo, hi});
      }
      if (firstList[l][1] < secondList[r][1]) {
        l++;
      } else {
        r++;
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}
