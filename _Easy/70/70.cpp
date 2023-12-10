#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
经典爬楼梯
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

dp[i] 表示爬到 i 台阶有几种方法
dp[0] = 1
dp[1] = 1
dp[2] = dp[1] + dp[0] = 2
dp[3] = dp[2] + dp[1] = 3
dp[4] = dp[2] + dp[3] = 5
1 1 2 3 5 8 .... 斐波那契

方法一：动态规划 滚动数组
vector<int> dp(n + 1);
dp[0] = 1;
dp[1] = 1;
for (int i = 2; i <= n; i++) {
    dp[i] += dp[i - 1] + dp[i - 2];
}
return dp[n];

p = 0, q = 0, r = 1
for (int i = 1; i <= n; i++) {
    p = q; // f[0] = f[1]
    q = r; // f[1] = f[2]
    r = p+q; // f[2] = f[1]+f[2]
}


方法二：矩阵快速幂 https://leetcode.cn/problems/climbing-stairs/solutions/286022/pa-lou-ti-by-leetcode-solution/
  1 1   fn
  1 0   fn-1

fn+1    1 1 f1
fn   =  1 0 f0

方法三：通项公式
double sqrt5 = sqrt(5);
double fibn = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
return (int)round(fibn / sqrt5);

 */
class Solution {
 public:
  int climbStairs(int n) {
    int p = 0, q = 0, r = 1;
    for (int i = 1; i <= n; i++) {
      p = q;      // f[0] = f[1]
      q = r;      // f[1] = f[2]
      r = p + q;  // f[2] = f[1]+f[2]
    }
    return r;
  }
};
int main() {

  Solution test;
  return 0;
}
