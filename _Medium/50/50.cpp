
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
实现 pow(x, n) ，即计算 x 的整数 n 次幂函数（即，xn ）。

x^77
77
 1 0 0 1 1 0 1
64     8 4 1
x^64 * x^8 * x^4 * x^1

用一个循环控制 n，表示求二进制
最初的位是 x^1，每次都递增 2 4 6 8
如果是当前位是 1 则乘上该位
*/
class Solution {
 public:
  double qpow(double x, long long n) {
    double ans = 1.0;
    double x_ = x;
    while (n) {
      if (n & 1) {
        ans *= x_;
      }
      x_ *= x_;
      n >>= 1;
    }
    return ans;
  }
  double myPow(double x, int n) {
    long long N = n;
    return N >= 0 ? qpow(x, N) : 1.0 / qpow(x, -N);
  }
};
int main() {

  Solution test;
  return 0;
}