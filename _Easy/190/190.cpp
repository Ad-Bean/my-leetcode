#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
颠倒给定的 32 位无符号整数的二进制位。

方法一：位运算
将 n 最后一位左移 31-i 位，ans |= 这位
n >>= 1 右移

方法二：位运算分治
对于递归的最底层，我们需要交换所有奇偶位
取出所有奇数、偶数位
奇数位移到偶数位 ，偶数位移到奇数位
对于倒数第二层，每两位分一组，按组号取出所有奇数组和偶数组，然后将奇数组移到偶数组上，偶数组移到奇数组上。
以此类推。

const uint32_t M1 = 0x55555555; // 01010101010101010101010101010101
const uint32_t M2 = 0x33333333; // 00110011001100110011001100110011
const uint32_t M4 = 0x0f0f0f0f; // 00001111000011110000111100001111
const uint32_t M8 = 0x00ff00ff; // 00000000111111110000000011111111

n = n >> 1 & M1 | (n & M1) << 1;
n = n >> 2 & M2 | (n & M2) << 2;
n = n >> 4 & M4 | (n & M4) << 4;
n = n >> 8 & M8 | (n & M8) << 8;
return n >> 16 | n << 16;


*/
class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;
    for (int i = 0; i < 32 && n > 0; i++) {
      ans |= (n & 1) << (31 - i);
      n >>= 1;
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}
