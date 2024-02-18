#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
给你一个整数 n ，共有编号从 0 到 n - 1 的 n 个会议室。

给你一个二维整数数组 meetings ，其中 meetings[i] = [starti, endi] 
表示一场会议将会在 半闭 时间区间 [starti, endi) 举办。所有 starti 的值 互不相同 。

会议将会按以下方式分配给会议室：

每场会议都会在未占用且编号 最小 的会议室举办。
如果没有可用的会议室，会议将会延期，直到存在空闲的会议室。延期会议的持续时间和原会议持续时间 相同 。
当会议室处于未占用状态时，将会优先提供给原 开始 时间更早的会议。
返回举办最多次会议的房间 编号 。如果存在多个房间满足此条件，则返回编号 最小 的房间。

半闭区间 [a, b) 是 a 和 b 之间的区间，包括 a 但 不包括 b 。

输入：n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
输出：0
 
输入：n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
输出：1

1 <= n <= 100
1 <= meetings.length <= 1e5
meetings[i].length == 2
0 <= starti < endi <= 5 * 1e5
starti 的所有值 互不相同

方法一：堆
对于分配问题，一般使用堆进行贪心。
使用最小堆，维护在 t 时刻空闲的会议室编号

对 meetings 按照开始时间排序，遍历每个会议
如果有空闲的会议室，弹出最小的
如果没有空闲的会议室，延期会议，所以还需要记录一个在使用的会议室编号，用最小堆存储其结束时间

! 由于 endi <= 5 * 1e5 并且 length <= 1e5, 1e5 * 5 * 1e5 = 5 * 1e10 > INT_MAX = 2147483647 ~ 2 * 1e9
使用 long 存储时间
*/

typedef pair<long, int> pll;
class Solution {
 public:
  int mostBooked(int n, vector<vector<int>>& meetings) {
    if (n == 1) {
      return 0;
    }
    vector<int> cnt(n);  // 记录每个会议室的使用次数
    priority_queue<int, vector<int>, greater<int>> hp;
    for (int i = 0; i < n; i++) {
      hp.emplace(i);
    }
    priority_queue<pll, vector<pll>, greater<pll>> occ;  // 记录每个会议室的结束时间
    sort(meetings.begin(), meetings.end(), [](const auto& a, const auto& b) { return a[0] < b[0]; });
    for (const auto& meeting : meetings) {
      long st = meeting[0], ed = meeting[1];
      int room = -1;

      // 当前时间 st，如果占用的会议室结束时间小于等于当前时间，就释放
      while (!occ.empty() && occ.top().first <= st) {
        hp.emplace(occ.top().second);
        occ.pop();
      }

      if (!hp.empty()) {
        room = hp.top();
        hp.pop();
      } else {
        auto [nxed, nxroom] = occ.top();  // 下次结束时间 nxed
        occ.pop();                        //
        ed = nxed + (ed - st);            // 下次结束时间
        room = nxroom;
      }
      cnt[room]++;
      occ.emplace(ed, room);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (cnt[i] > cnt[ans]) {
        ans = i;
      }
    }
    return ans;
  }
};

int main() {
  Solution test;
  int n = 3;
  vector<vector<int>> meetings = {{1, 20}, {2, 10}, {3, 5}, {4, 9}, {6, 8}};
  cout << test.mostBooked(n, meetings) << endl;
  return 0;
}
