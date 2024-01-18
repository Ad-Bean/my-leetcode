#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.
-2^31 <= n <= 2^31 - 1

方法一：暴力
n 不断除以 3，直到 n == 1

方法二：判断是否为 最大3的幂 的约数

3^19 == 1162261467
return n > 0 && 1162261467 % n == 0; 
 */
class Solution {
 public:
  bool isPowerOfThree(int n) {
    while (n && n % 3 == 0) {
      n /= 3;
    }
    return n == 1;
  }
};
int main() {

  Solution test;
  return 0;
}
