
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个 无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入 **一个新的区间**，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。


输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
输出：[[1,5],[6,9]]

输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
输出：[[1,2],[3,10],[12,16]]
解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。


方法一：分类讨论
int l = newInterval[0], r = newInterval[1];

两个区间 l1, r1 和 l2, r2 如果没有交集则 r1 < l2 或 r2 < l1
否则有交集 [max(l1,l2), min(r1,r2)]
并集 [min(l1,l2), max(r1,r2)]

所以对于本题，找到所有和 [l,r] 重叠的区间
将这些区间合并

注意：emplace_back({l, r}) 是错误语法，没有调用构造函数
 */
class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int l = newInterval[0], r = newInterval[1];
    vector<vector<int>> ans;
    bool inserted = false;
    for (const auto& interval : intervals) {
      if (interval[1] < l) {
        // 无交集，在左边
        ans.emplace_back(interval);
      } else if (interval[0] > r) {
        // 无交集，在右边
        if (!inserted) {
          // 如果还没有插入，插入合并后的区间
          ans.push_back({l, r});
          inserted = true;
        }
        ans.emplace_back(interval);
      } else {
        // 有交集，得到并集
        l = min(l, interval[0]);
        r = max(r, interval[1]);
      }
    }
    // 如果还没有插入，插入合并后的区间
    if (!inserted) {
      ans.push_back({l, r});
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}