#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个二维整数数组 ranges ，其中 ranges[i] = [starti, endi] 
表示 starti 到 endi 之间（包括二者）的所有整数都包含在第 i 个区间中。

你需要将 ranges 分成 两个 组（可以为空），满足：

每个区间只属于一个组。
两个有 交集 的区间必须在 同一个 组内。
如果两个区间有至少 一个 公共整数，那么这两个区间是 有交集 的。

比方说，区间 [1, 3] 和 [2, 5] 有交集，因为 2 和 3 在两个区间中都被包含。
请你返回将 ranges 划分成两个组的 总方案数 。由于答案可能很大，将它对 109 + 7 取余 后返回。

输入：ranges = [[6,10],[5,15]]
输出：2
解释：
两个区间有交集，所以它们必须在同一个组内。
所以有两种方案：
- 将两个区间都放在第 1 个组中。
- 将两个区间都放在第 2 个组中。


1 <= ranges.length <= 10^5

方法一：并查集 + 排序
由于是合并，所以可以考虑并查集求连通块个数
先将区间按照左端点排序，遍历区间
如果 nums[i][0] <=  lastMaxRightEndpoint 则可以合并
注意这个 lastMaxRightEndpoint 是上一个合并后区间的最大右端点

最后返回 2^连通块个数，注意使用带 mod 的快速幂

方法二：合并区间 + 排序
实际上可以不用并查集，只需要合并区间即可
按照左端点排序后，维护一个 lastMaxRightEndpoint 表示当前合并区间的最右端点
sort(ranges.begin(), ranges.end(), [&](const auto& a, const auto& b) { return a[0] < b[0]; });
int ans = 1, max_r = -1, n = ranges.size();
for (int i = 0; i < n; i++) {
    if (ranges[i][0] > max_r) { // 无交集
        ans = ans * 2 % mod;    // 乘 2
        max_r = ranges[i][1];   // 更新最右端点
    } else {
        max_r = max(max_r, ranges[i][1]); // 合并
    }
}
return ans;
 */
class Solution {
 public:
  int countWays(vector<vector<int>>& ranges) {
    const int mod = 1e9 + 7;
    int n = ranges.size();
    sort(ranges.begin(), ranges.end(), [&](const auto& a, const auto& b) { return a[0] < b[0]; });
    vector<int> fa(n);
    iota(fa.begin(), fa.end(), 0);
    vector<int> sz(n, 1);

    function<int(int)> find = [&](int x) {
      return fa[x] == x ? x : fa[x] = find(fa[x]);
    };

    int count = n;
    function<void(int, int)> merge = [&](int x, int y) {
      int fx = find(x), fy = find(y);
      if (fx == fy) {
        return;
      }
      if (sz[fx] < sz[fy]) {
        sz[fy] += sz[fx];
        fa[fx] = fy;
        count--;
      } else {
        sz[fx] += sz[fy];
        fa[fy] = fx;
        count--;
      }
    };
    int lastMaxRightEndpoint = ranges[0][1];
    for (int i = 1; i < n; i++) {
      if (ranges[i][0] <= lastMaxRightEndpoint) {
        merge(i, i - 1);
        lastMaxRightEndpoint = max(lastMaxRightEndpoint, ranges[i][1]);
      } else {
        lastMaxRightEndpoint = ranges[i][1];
      }
    }

    function<int(int, int)> quick_pow = [&](int a, int p) {
      long long res = 1;
      long long ppp = a;
      while (p) {
        if (p & 1) {
          res = res * ppp % mod;
        }
        ppp = ppp * ppp % mod;
        p >>= 1;
      }
      return (int)res;
    };
    return quick_pow(2, count);
  }
};
int main() {

  Solution test;
  vector<vector<int>> ranges = {{6, 10}, {5, 15}};
  cout << test.countWays(ranges) << endl;
  return 0;
}
