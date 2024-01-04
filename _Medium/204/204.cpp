#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给定整数 n, 0 <= n <= 5 * 1e6 ，返回 所有小于非负整数 n 的质数的数量 。

方法一： 枚举 O(n * sqrt(n))
for (int i = 2; i <= n; i++) {
 for (int j = 2; j * j <= i; j++) {
    if (i % j == 0) { break; }
 }
}

方法二：埃氏筛 O(nloglogn)
如果 x 是质数，则 2x 3x... 不是质数
继续优化，对于一个质数 x，如果按上文说的我们从 2x 开始标记其实是冗余的，
应该直接从 x * x 开始标记，因为 2x,3x, 这些数一定在 x 之前就被其他数的倍数标记过了，例如 2 的所有倍数，3 的所有倍数等。

方法三：线性筛 O(n)
埃氏筛其实还是存在冗余的标记操作，比如对于 45，它会同时被 3, 5 两个数标记为合数

线性筛在标记过程中，对所有 x 进行标记，标记 x * primes[0], x * primes[1] 直到 x % primes[i] == 0

如果 x 可以被 primes[i] 整除，则 y = x * primes[i + 1] 一定会在后面 x/primes[i] * primes[i+1] 被重复标记
 */
class Solution {
 public:
  int countPrimes(int n) {
    vector<int> primes;
    vector<bool> isPrime(n);
    for (int i = 2; i < n; i++) {
      if (!isPrime[i]) {
        primes.emplace_back(i);
      }
      for (int j = 0; j < primes.size() && i * primes[j] < n; j++) {
        isPrime[i * primes[j]] = true;
        if (i % primes[j] == 0) {
          break;
        }
      }
    }
    return primes.size();
  }
};
int main() {

  Solution test;
  return 0;
}
