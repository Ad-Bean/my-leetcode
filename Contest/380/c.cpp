#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
/* 
给你一个整数 k 和一个整数 x 。

令 s 为整数 num 的下标从 1 开始的二进制表示。我们说一个整数 num 的 价值 是满足 i % x == 0 且 s[i] 是 设置位 的 i 的数目。

请你返回 最大 整数 num ，满足从 1 到 num 的所有整数的 价值 和小于等于 k 。

注意：

一个整数二进制表示下 设置位 是值为 1 的数位。
一个整数的二进制表示下标从右到左编号，比方说如果 s == 11100 ，那么 s[4] == 1 且 s[2] == 0 。

输入：k = 9, x = 1
输出：6
解释：数字 1 ，2 ，3 ，4 ，5 和 6 二进制表示分别为 "1" ，"10" ，"11" ，"100" ，"101" 和 "110" 。
由于 x 等于 1 ，每个数字的价值分别为 所有设置位的数目。
这些数字的所有设置位数目总数是 9 ，所以前 6 个数字的价值和为 9 。
所以答案为 6 

输入：k = 7, x = 2
输出：9
解释：由于 x 等于 2 ，我们检查每个数字的偶数位。
2 和 3 在二进制表示下的第二个数位为设置位，所以它们的价值和为 2 。
6 和 7 在二进制表示下的第二个数位为设置位，所以它们的价值和为 2 。
8 和 9 在二进制表示下的第四个数位为设置位但第二个数位不是设置位，所以它们的价值和为 2 。
数字 1 ，4 和 5 在二进制下偶数位都不是设置位，所以它们的价值和为 0 。
10 在二进制表示下的第二个数位和第四个数位都是设置位，所以它的价值为 2 。
前 9 个数字的价值和为 6 。
前 10 个数字的价值和为 8，超过了 k = 7 ，所以答案为 9 。

1 <= k <= 1e15
1 <= x <= 8

方法一：二分答案 + 数位 DP O((x+logk)^3) 二分 * 数位 DP
什么时候能够二分答案：1 到 num 数字越大，和越大，服从单调性，在有序数组上查一个小于等于 k 的最大的 num，即二分
如何 check：给定 num，统计 1 - num 的价值和，判断价值和是否 <= k

数位 DP leetcode 233 给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数
https://leetcode.cn/problems/number-of-digit-one/

__builtin_clzll 求出 num 此时有多少个前导 0
int m = 64 - clz; // 表示一共有多少位 
枚举 1 到 1<< (m-1) 中，第 (i+1) %x == 0 的和

m 表示最高位 1 的位置，
如果入口是 dfs(m, 0, true) 则终止在 i == 0, lo = 0, hi = isLimit ? num >> (i-1) & 1 : 1, 当前位是 i
dfs(i - 1, cnt + (d == 1 && (i + 1) % x == 0), isLimit && d == up);

如果入口是 dfs(m-1,0,true) 则终止在 i <  0, lo = 0, hi = isLimit ? num >>     i & 1 : 1, 当前位是 i + 1
dfs(i - 1, cnt + (d == 1 && (i + 1) % x == 0), isLimit && d == up);


二分上下界：
下界：1
假设 x = 1 此时最低位 0101 变化，则 2k
假设 x = 2 此时 k * (1 << x) 则是
所以上界是 k * 2^x 即 k << x， 可以适当加一点比如 (k+1) << x

方法二：二分答案 + 数学公式 O(log^2(k) / x)
 */
class Solution {
  typedef long long ll;

 public:
  long long findMaximumNumber(long long k, int x) {

    auto check = [&](ll num) {
      int m = 64 - __builtin_clzll(num);  // k <= 1e15 此时用 long long 64 位，求出有多少个前导 0
      vector<vector<ll>> dp(m, vector<ll>(m + 1, -1));
      function<ll(int, int, bool)> dfs = [&](int i, int cnt, bool isLimit) -> ll {
        if (i <= 0) {
          return cnt;
        }
        if (!isLimit && dp[i][cnt] >= 0) {
          return dp[i][cnt];
        }
        ll res = 0;
        for (int d = 0, up = isLimit ? num >> (i - 1) & 1 : 1; d <= up; d++) {
          res += dfs(i - 1, cnt + (d == 1 && (i) % x == 0), isLimit && d == up);
        }
        if (!isLimit) {
          dp[i][cnt] = res;
        }
        return res;
      };
      return dfs(m, 0, true) <= k;
    };

    ll l = 1, r = (k + 1) << x;
    while (l <= r) {
      ll mid = l + (r - l) / 2;
      if (check(mid)) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return r;
  }
};
int main() {
  Solution test;
  cout << test.findMaximumNumber(100, 2) << endl;
  return 0;
}