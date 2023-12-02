
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
差分数组

对 trips[i]，假设当前车上人数为 x
需要判断所有 trips[i] 都不超过 cap

需要对 trips[i] 从 from -> to - 1 中的 trips[j][0] 加上乘客数


输入：trips = [[2,1,5],[3,3,7]], capacity = 4
输出：false

因为 d[1] = 2, d[5] = -2, d[3] = 3, d[7] = -3
从左到右累加
a=[0,2,2,5,5,3,3,0,⋯] 其中 max(a) > cap = 4，返回 false

0 <= fromi < toi <= 1000，数组长度为 1005 不会越界
 */
class Solution {
 public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    int d[1005]{};
    for (const auto& trip : trips) {
      d[trip[1]] += trip[0];
      d[trip[2]] -= trip[0];
    }
    // 累加
    int s = 0;
    for (const int& a : d) {
      s += a;
      if (s > capacity) {
        return false;
      }
    }
    return true;
  }
};
int main() {

  Solution test;
  return 0;
}