#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/*
leetcode 50：快速幂
比如 77（1001101）
     77   38     19      9      4      2       1        0
ans  x    x      x^5    x^13   x^13   x^13    x^77     x^77 
x_   x^2  x^4    x^8    x^16   x^32   x^64    x^128   x^256
*/
/* 
随意填字母的方案数 - 不合法方案数
26^n - (3 * 25^n + n*25^(n-1)) + (3 * 24^n + 2*n*24^(n-1))
= 26^n - (75 + n)*25^(n-1) + (72+2*n)*24^(n-1) - (23 + n)*23^(n-1)

不合法方案数，至少满足下面的条件：
!至少一个 l -> 不包含 l
!至少一个 t -> 不包含 t
!至少两个 e -> 至多一个，不包含或者恰好一个 e

A: 不包含 l: 25^n
B: 不包含 t: 25^n
C: 至多一个，不包含  25^n, 或者恰好一个 e n * 25^(n-1): 25^n + n*25^(n-1)
A and B: 没有 l 也没有 t： 24^n
A and C: 没有 l 且 不包含或者恰好一个 e：24^n + n*24^(n-1)
B and C: 没有 t 且 不包含或者恰好一个 e：24^n + n*24^(n-1)

A and B and C: 23^n + n*23^(n-1) = (23 + n) * 23^(n-1)
 */
typedef long long ll;
class Solution {
  const ll mod = 1e9 + 7;
  ll quickPow(int x, int n) {
    ll ans = 1;
    ll x_ = x;
    while (n > 0) {
      if (n & 1) {
        ans = (ans * x_) % mod;
      }
      x_ = (x_ * x_) % mod;
      n >>= 1;
    }
    return ans;
  }

 public:
  int stringCount(int n) {
    ll ans = quickPow(26, n);
    ans -= quickPow(25, n - 1) * (75 + n);
    ans += quickPow(24, n - 1) * (72 + 2 * n);
    ans -= quickPow(23, n - 1) * (23 + n);
    ans %= mod;
    ans += mod;
    ans %= mod;
    return ans;
  }
};
int main() {
  int i = 1;
  cout << ++i++ << endl;
  return 0;
}