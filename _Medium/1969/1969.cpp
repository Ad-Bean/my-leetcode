#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
/* 
给你一个正整数 p 。你有一个下标从 1 开始的数组 nums ，这个数组包含范围 [1, 2^p - 1] 内所有整数的二进制形式（两端都 包含）。
你可以进行以下操作 任意 次：

从 nums 中选择两个元素 x 和 y  。
选择 x 中的一位与 y 对应位置的位交换。对应位置指的是两个整数 相同位置 的二进制位。
比方说，如果 x = 1101 且 y = 0011 ，交换右边数起第 2 位后，我们得到 x = 1111 和 y = 0001 。

请你算出进行以上操作 任意次 以后，nums 能得到的 最小非零 乘积。将乘积对 1e9 + 7 取余 后返回。

注意：答案应为取余 之前 的最小值。

输入：p = 1
输出：1
解释：nums = [1] 。
只有一个元素，所以乘积为该元素。

输入：p = 2
输出：6
解释：nums = [01, 10, 11] 。
所有交换要么使乘积变为 0 ，要么乘积与初始乘积相同。
所以，数组乘积 1 * 2 * 3 = 6 已经是最小值。

输入：p = 3
输出：1512
解释：nums = [
    001, 
    010, 
    011, 

    100, 
    101, 
    110, 
    111]
- 第一次操作中，我们交换第二个和第五个元素最左边的数位。
    - 结果数组为 [
    001,  
    110,  
    011,  
    100,  
    001,  
    110,  
    111] 
- 第二次操作中，我们交换第三个和第四个元素中间的数位。
    - 结果数组为 [
    001, 
    110, 
    001, 
    110, 
    001, 
    110, 
    111] 。
数组乘积 1 * 6 * 1 * 6 * 1 * 6 * 7 = 1512 是最小乘积。
 
方法一：贪心
a * b > (a - 2^i) * (b + 2^i) 有 a * b > a * b + 2^i * a - 2^i * b - 2^2i
2^i * (a - b) < 2^2i
a - b < 2^i
a < b + 2^i
所以对每个数，如果 a - b > 2^i 则可以交换第 i 位
a > b + 2^i 只要原本的 a < 交换后的 b 就可以一直交换

将 [1, 2^p - 1] 分成两组，
001 对应 110  
010 对应 101 可以变成 110 和 001
011 对应 100 可以变成 001 和 110

此时看出，除去 2^p - 1 外，分成两组对应，可以变成 2^p - 2 和 1
一共有 (2^(p) - 1  - 1) / 2 = 2^(p-1) - 1 对
所以最后答案是  (2^p - 2)^(2^(p - 1) - 1) * (2^p - 1)

所以需要快速幂（取模）
注意细节：2^p - 2 也是 long long
1 << p 会溢出，也需要取模
 */
typedef long long ll;
class Solution {

  const int mod = 1e9 + 7;
  ll pow(ll x, ll power) {
    x %= mod;
    ll res = 1;
    while (power) {
      if (power & 1) {
        res = res * x % mod;
      }
      x = x * x % mod;
      power >>= 1;
    }
    return res;
  }

 public:
  int minNonZeroProduct(int p) {
    ll x = (1LL << p) % mod;
    ll xx = (1LL << (p - 1));
    return pow(x - 2, xx - 1) % mod * (x - 1) % mod;
  }
};
int main() {

  Solution test;
  //   cout << test.minNonZeroProduct(3) << endl;
  cout << test.minNonZeroProduct(31) << endl;  // 138191773
  return 0;
}
