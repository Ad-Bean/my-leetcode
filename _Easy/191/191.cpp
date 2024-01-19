#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/* 
number of 1 bits

log(n): n &= n - 1, checks if n is a power of 2

11 -> 1011
10 -> 1010    [ n &= (11-1) => 8], change the righest 1 to 0
 8 -> 1000    [ n &= (10-1) ]
 0 -> 0000    [ n &= (8-1) ]


C++ 
__builtin_popcount

 */
class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int cnt = 0;
    while (n) {
      n &= n - 1;
      cnt++;
    }
    return cnt;
  }
};

int main() {

  Solution test;
  return 0;
}
