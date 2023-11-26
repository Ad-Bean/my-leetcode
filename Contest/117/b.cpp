#include <bits/stdc++.h>
using namespace std;

/* 
容斥原理：合法方案数 = 不考虑 limit 方案数 - 不合法方案数

不考虑 limit 方案数：
对 n 个小球，放入三个分区，隔板法：n+2 个空位放两个板子， C(n+2, 2)

不合法方案数：
至少有一个大于 limit：
甲大于 limit + 乙大于 limit + 丙大于 limit - 甲乙 - 甲丙 - 乙丙 + 甲乙丙 > limit
甲分 limit + 1，剩下 n - limit - 1
C(n- 1*(limit+1) +2, 2) 
C(n- 2*(limit+1) +2, 2)
C(n- 3*(limit+1) +2, 2)

C(n+2,2) - 3*C(n- 1*(limit+1) +2, 2)  + 3*C(n- 2*(limit+1) +2, 2) - C(n- 3*(limit+1) +2, 2)
*/
typedef long long ll;
class Solution {
  ll C2(ll n) {
    if (n > 1) {
      return n * (n - 1) / 2;
    }
    return 0;
  }

 public:
  long long distributeCandies(int n, int limit) {

    return c2(n + 2) - 3 * c2(n - (limit + 1) + 2) + 3 * c2(n - 2 * (limit + 1) + 2) - c2(n - 3 * (limit + 1) + 2);
  }
  // long long distributeCandies(int n, int limit) {
  //   ll upper = (n + 2) * (n + 1) / 2LL;
  //   if (upper > n / 2) {
  //     return upper - (6 + 3 * (n - limit - 1)) * (n - limit) / 2;
  //   }
  //   ll ans = 0;
  //   for (int i = 0; i < min(n, limit) + 1; i++) {
  //     ll l = max(0, n - i - limit), r = min(n - i, limit);
  //     if (r >= l)
  //       ans += r - l + 1;
  //   }
  //   return ans;
  // }
};
int main() {

  Solution test;
  cout << test.distributeCandies(11, 1) << endl;
  cout << test.distributeCandies(11, 2) << endl;
  cout << test.distributeCandies(11, 3) << endl;
  cout << test.distributeCandies(11, 4) << endl;
  cout << test.distributeCandies(11, 5) << endl;
  cout << test.distributeCandies(11, 6) << endl;

  return 0;
}