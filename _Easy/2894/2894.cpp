#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你两个正整数 n 和 m 。

现定义两个整数 num1 和 num2 ，如下所示：

num1：范围 [1, n] 内所有 无法被 m 整除 的整数之和。
num2：范围 [1, n] 内所有 能够被 m 整除 的整数之和。
返回整数 num1 - num2 。

输入：n = 10, m = 3
输出：19
解释：在这个示例中：
- 范围 [1, 10] 内无法被 3 整除的整数为 [1,2,4,5,7,8,10] ，num1 = 这些整数之和 = 37 。
- 范围 [1, 10] 内能够被 3 整除的整数为 [3,6,9] ，num2 = 这些整数之和 = 18 。
返回 37 - 18 = 19 作为答案。

方法一：数学
不能被 m 整除的数的和，(1 + n) * n / 2 -  (m + n/m * m) * n/m / 2
能被 m 整除的数：m, 2m, 3m, ... , n/m * m，和为 (m + n/m * m) * n/m / 2 

最后返回差： (1 + n) * n / 2 -  (m + n/m * m) * n/m 
 */
class Solution {
 public:
  int differenceOfSums(int n, int m) {
    if (m == 1) {
      return -(1 + n) * n / 2;
    }
    int cnt = n / m;
    if (m <= n) {
      return (1 + n) * n / 2 - (m + cnt * m) * cnt;
    } else {
      return (1 + n) * n / 2;
    }
  }
};
int main() {

  Solution test;
  cout << test.differenceOfSums(10, 3) << endl;
  cout << test.differenceOfSums(5, 6) << endl;
  cout << test.differenceOfSums(5, 1) << endl;
  return 0;
}