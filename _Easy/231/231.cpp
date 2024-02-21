#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个整数 n，请你判断该整数是否是 2 的幂次方。如果是，返回 true ；否则，返回 false 。

如果存在一个整数 x 使得 n == 2^x ，则认为 n 是 2 的幂次方。

方法一：位运算
如果 n 是 2 的幂，那么 n 的二进制表示中有且仅有一个 1，即最高位为 1，其余所有位为 0。

lowbit: x & -x 得到最低位的 1 的值, if (x & -x) == x, x 是 2 的幂次方
and: x & (x - 1) 去掉最低位的 1, if (x & (x - 1)) == 0, x 是 2 的幂次方

方法二：数学
32 位有符号整数范围是 [-2^31, 2^31 - 1]，最大的 2 的幂次方是 2^30
如果 n 是 2 的幂次方，那么 2^30 % n == 0
 */
class Solution {
 public:
  bool isPowerOfTwo(int n) { return n > 0 && (n & -n) == n; }
};
int main() {

  Solution test;
  return 0;
}
