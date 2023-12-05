
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
输入：n = 7
输出：6
7/2 + 4/2 + 2/2


输入：n = 14
输出：13



 */
class Solution {
 public:
  int numberOfMatches(int n) {
    // int sum = 0;
    // while (n != 1) {
    //   sum += n / 2;
    //   n = (n + 2 - 1) / 2;
    // }
    // return sum;
    return n - 1;
  }
};
int main() {

  Solution test;
  return 0;
}