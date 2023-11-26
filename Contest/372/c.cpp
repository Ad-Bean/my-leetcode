#include <bits/stdc++.h>
using namespace std;
/* 
输入：a = 12, b = 5, n = 4
输出：98
解释：当 x = 2 时，(a XOR x) = 14 且 (b XOR x) = 7 。所以，(a XOR x) * (b XOR x) = 98 。
98 是所有满足 0 <= x < 2n 中 (a XOR x) * (b XOR x) 的最大值。

x = 2,  0010
1100  ^ 0010 = 1110 = 14
0101  ^ 0010 = 0111 = 7

1100  ^ 1001 = 0101 = 5
0101  ^ 1001 = 1100 = 12


输入：a = 1, b = 6, n = 3
输出：12
解释： 当 x = 5 时，(a XOR x) = 4 且 (b XOR x) = 3 。所以，(a XOR x) * (b XOR x) = 12 。
12 是所有满足 0 <= x < 2n 中 (a XOR x) * (b XOR x) 的最大值。

为什么不是贪心
001 ^ 101 = 100 = 4
110 ^ 101 = 011 = 3

贪心
001 ^ 100 = 101 = 1
110 ^ 100 = 010 = 6
 */
typedef long long ll;

class Solution {
 public:
  int maximumXorProduct(ll a, ll b, int n) {
    const int mod = 1e9 + 7;
    ll aa = (a - (a & ((1 << n) - 1))), bb = (b - (b & ((1 << n) - 1)));
    for (int i = n - 1; i >= 0; i--) {
      ll cur = (1 << i);
      ll bita = a & cur, bitb = b & cur;
      if (bita == bitb) {
        aa |= cur;
        bb |= cur;
      } else {
        if (aa > bb) {
          bb |= cur;
        } else {
          aa |= cur;
        }
      }
    }
    return ((aa % mod) * (bb % mod)) % mod;
  }
};

int main() {
  Solution solution;
  cout << solution.maximumXorProduct(12, 5, 4) << endl;  // 输出：98
  cout << solution.maximumXorProduct(6, 7, 5) << endl;   // 输出：930
  cout << solution.maximumXorProduct(1, 6, 3) << endl;   // 输出：12

  return 0;
}