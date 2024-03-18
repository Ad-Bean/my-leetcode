
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 

1611. 使整数变为 0 的最少操作次数

给你一个整数 n，你需要重复执行多次下述操作将其转换为 0 ：

翻转 n 的二进制表示中最右侧位（第 0 位）。
如果第 (i-1) 位为 1 且从第 (i-2) 位到第 0 位都为 0，则翻转 n 的二进制表示中的第 i 位。
返回将 n 转换为 0 的最小操作次数。

0 <= n <= 1e9

输入：n = 3
输出：2
解释：3 的二进制表示为 "11"
"11" -> "01" ，执行的是第 2 种操作，因为第 0 位为 1 。
"01" -> "00" ，执行的是第 1 种操作。

输入：n = 6
输出：4
解释：6 的二进制表示为 "110".
"110" -> "010" ，执行的是第 2 种操作，因为第 1 位为 1 ，第 0 到 0 位为 0 。
"010" -> "011" ，执行的是第 1 种操作。
"011" -> "001" ，执行的是第 2 种操作，因为第 0 位为 1 。
"001" -> "000" ，执行的是第 1 种操作。

方法一：找规律递归

n
1   0001   1
2   0010   3 
3   0011   2
4   0100   7    = 7
5   0101   6    = 7 - 1
6   0110   4    = 7 - 3
7   0111   5    = 7 - 3 + 1     
8   1000  15    = 15
9   1001  14    = 15 - 1
10  1010  12    = 15 - 3
11  1011  13    = 15 - 3 + 1

如果 n 是 2 的幂，则操作数是 2 * n - 1
否则，n 可以分解， n = 2^i + y 
n = 10 = 8 + 2
2 的操作数是 3
则 n = 10 的操作数是 15 - 3 = 12
dp[n] = dp[2^i] - dp[n - 2^i]

简洁写法：
if (n == 0 || n == 1) {
    return n;
}
int x = 31 - __builtin_clz(n);
return 
        ((1 << (x + 1)) - 1)
         - 
        minimumOneBitOperations(n - (1 << x));

__builtin_clz(n) 返回 n 的二进制表示中前导 0 的个数
31 - __builtin_clz(n) 返回 n 的二进制表示中最高位 1 的位置

方法二：迭代
int ans = 0;
int sign = 1;
for (int i = 29; i >= 0; --i) {
    if (n & (1 << i)) {
        ans += sign * ((1 << (i + 1)) - 1);
        sign = -sign;
    }
}
return ans;


方法三：格雷码
将 n 看成格雷码，转换成对应的二进制码，就可以得到答案。
int ans = 0;
while (n) {
    ans ^= n;
    n >>= 1;
}
return ans;
 */
class Solution {
 public:
  int minimumOneBitOperations(int n) {
    if (n == 1) {
      return 1;
    }
    for (int i = 31; i >= 0; i--) {
      if ((n >> i) & 1) {
        int a = (1 << (i + 1)) - 1;
        int b = n - (1 << i);
        return a - minimumOneBitOperations(b);
      }
    }
    return 0;
  }
};
int main() {

  Solution test;
  cout << test.minimumOneBitOperations(3) << endl;
  cout << test.minimumOneBitOperations(10) << endl;
  return 0;
}