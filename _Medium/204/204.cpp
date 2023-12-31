#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给定整数 n, 0 <= n <= 5 * 1e6 ，返回 所有小于非负整数 n 的质数的数量 。

方法一： 枚举 On * sqrt(n)
for (int i = 2; i <= n; i++) {
 for (int j = 2; j * j <= i; j++) {
    if (i % j == 0) { break; }
 }
}

方法二：埃氏筛


 */
class Solution {
 public:
  int countPrimes(int n) {}
};
int main() {

  Solution test;
  return 0;
}
