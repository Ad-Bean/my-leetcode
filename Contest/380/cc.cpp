#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

/* 
方法二：二分答案 + 数学公式 O(log^2(k) / x)
1 到 num=6  的二进制 
001             
010             
011             
100             
101             
110             
​计算 1 到 num 的每个比特位上有多少个 1。
最低位：相当于计算 1 到 num 中有多少个奇数，这有 num / 2=3 个
次低位：我们可以把每个数都除以 2（右移 1 位），忽略 00，此时 1 到 num/2 - 1 中的1 出现两次，而 num/2 只出现一次，低位就3个1
第三位：右移 2 位，此时 1 到 num/4 - 1 每个奇数出现 4 次，但 num/4 = 1 出现了 3 次，num = 6 AND 2^2-1=3 得到 2 说明把 num / 4 做前缀的二进制数最低位是 00 01 10

从低到高，i 从 0 开始的 1 的个数：
1. n = num / 2^i 从 1 到 n-1 一共有 n/2 个奇数，一共有 (n/2) * 2^i 个 1
2. n 单独作为 1 到 num 的二进制数前缀，出现了 num&(2^i-1) + 1 次，n 如果是奇数则贡献了 num&(2^i-1) + 1 个 1 否则 0 个


 */
class Solution {
 public:
  long long findMaximumNumber(long long k, int x) {
    auto check = [&](long long num) {
      long long res = 0;
      int i = x - 1;
      for (long long n = num >> i; n; n >>= x, i += x) {
        res += (n / 2) << i;
        if (n % 2) {
          long long mask = (1LL << i) - 1;
          res += (num & mask) + 1;
        }
      }
      return res <= k;
    };

    long long left = 0, right = (k + 1) << x;
    while (left + 1 < right) {
      long long mid = left + (right - left) / 2;
      (check(mid) ? left : right) = mid;
    }
    return left;
  }
};
/* 
方法三：逐位构造

 */
class Solution {
 public:
  long long findMaximumNumber(long long k, int x) {
    long long num = 0, pre1 = 0;
    for (long long i = 63 - __builtin_clzll((k + 1) << x); i >= 0; i--) {
      long long cnt = (pre1 << i) + (i / x << i >> 1);
      if (cnt <= k) {
        k -= cnt;
        num |= 1LL << i;
        pre1 += (i + 1) % x == 0;
      }
    }
    return num - 1;
  }
};

int main() {
  Solution test;
  cout << test.findMaximumNumber(100, 2) << endl;
  return 0;
}