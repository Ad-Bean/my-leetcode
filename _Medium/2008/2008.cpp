
#include <bits/stdc++.h>
using namespace std;

/* 
n 个地点，从 1 开到 n，同时只能接一个乘客
rides[i] = [start, end, tip]
盈利  end - start + tip
返回最优接单方案下最多盈利多少钱


方法一：动态规划 + 哈希表
! 最重要的条件：1 <= starti < endi <= n，如果没有就是排序后遍历 rides
假设 n=9, 从 1 开到 9 最多可以赚多少钱？
对 9 如果没有乘客下车，或者不带在 9 下车的乘客：问题转化 -> 从 1 开到 8 最多可以赚多少钱
对 9 如果有乘客下车，可以枚举带哪个乘客，比如乘客在 5 上车，那么 5 -> 9 不可以带其他乘客：问题转化 从 1 开到 5 最多可以赚多少钱

递归 -> 动态规划
dp[i] = dp[i - 1] 如果在 i 没有下车
dp[i] = max(dp[start_j] + i - start_j + tip_j)  如果在 i 下车，end == i
dp[i] = max(dp[i - 1], max(dp[start_j] + i - start_j + tip_j))
dp[1] = 0
--------------递推------------
由于 1 <= starti < endi <= n，所以可以记录

输入：n = 5, rides = [[2,5,4],[1,5,1]]
输出：7
解释：我们可以接乘客 0 的订单，获得 5 - 2 + 4 = 7 元。

输入：n = 20, rides = [[1,6,1],[3,10,2],[10,12,3],[11,12,2],[12,15,2],[13,18,1]]
输出：20
解释：我们可以接以下乘客的订单：
- 将乘客 1 从地点 3 送往地点 10 ，获得 10 - 3 + 2 = 9 元。
- 将乘客 2 从地点 10 送往地点 12 ，获得 12 - 10 + 3 = 5 元。
- 将乘客 5 从地点 13 送往地点 18 ，获得 18 - 13 + 1 = 6 元。
我们总共获得 9 + 5 + 6 = 20 元。

dp[1] = 0
dp[6] = max(dp[5], dp[1] + 6-1+1) = 6
dp[7] = 6 // 注意传递

方法二：动态规划 + 排序 + 二分
对 rides 按照 end_i 升序排序，
dp[i+1] 只接区间 [0,i] 内乘客的最大利益
对第 i 位乘客，如果接单，二分查找满足 end_j <= start_i 最大的 j，dp[i + 1] = dp[j] + end_i - start_i + tip_i
找 end 小于当前 start 的最大的 end
对第 i 位乘客，如果不接单，则 dp[i + 1] = dp[i]

dp[i + 1] = max(dp[i], dp[j] + end_i - start_i + tip_i) 

sort(rides.begin(), rides.end(), [&](const vector<int> &r1, const vector<int> &r2) -> bool {
    return r1[1] < r2[1]; // 按照 end_i 升序
});
int m = rides.size();
vector<long long> dp(m + 1);
for (int i = 0; i < m; i++) {
    int j = upper_bound(rides.begin(), rides.begin() + i, rides[i][0], [](int x, const vector<int> &r) -> bool {
        return x < r[1];
    }) - rides.begin();   // 找到 rides[:i] 中，第一个小于， rides[i][0] 也即当前起点，的终点的下标
    dp[i + 1] = max(dp[i], dp[j] + rides[i][1] - rides[i][0] + rides[i][2]);
}
return dp[m];

 */
typedef long long ll;
typedef pair<int, int> pii;
class Solution {
 public:
  long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
    vector<vector<pii>> ends(n + 1);
    for (const auto& ride : rides) {
      int st = ride[0], ed = ride[1], tip = ride[2];
      ends[ed].push_back({st, ed - st + tip});
    }

    vector<ll> dp(n + 1);
    for (int i = 1; i <= n; i++) {
      dp[i] = dp[i - 1];  // 传递
      // 有乘客在当前 end == i 下车，遍历所有 rides 在 end == i 下车的， 找到起点更新，取最大利润
      for (const auto& [st, earn] : ends[i]) {
        dp[i] = max(dp[i], dp[st] + earn);  // 内层用更新后的 dp[i] 而不是 dp[i-1]
      }
    }
    return dp[n];
  }
};

class Solution2 {
 public:
  long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
    sort(rides.begin(), rides.end(),
         [&](const vector<int>& r1, const vector<int>& r2) -> bool { return r1[1] < r2[1]; });
    int m = rides.size();
    vector<long long> dp(m + 1);
    for (int i = 0; i < m; i++) {
      int j = upper_bound(rides.begin(), rides.begin() + i, rides[i][0],
                          [](int x, const vector<int>& r) -> bool { return x < r[1]; }) -
              rides.begin();
      //   cout << "start: " << rides[i][0] << " first end:" << j << " " << endl;
      dp[i + 1] = max(dp[i], dp[j] + rides[i][1] - rides[i][0] + rides[i][2]);
    }
    return dp[m];
  }
};

int main() {

  Solution2 test;
  int n = 20;
  vector<vector<int>> rides = {
      {1, 6, 1}, {3, 10, 2}, {10, 12, 3}, {11, 12, 2}, {12, 15, 2}, {13, 18, 1},
  };
  cout << test.maxTaxiEarnings(n, rides) << endl;
  return 0;
}