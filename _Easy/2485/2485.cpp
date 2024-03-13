
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
Given a positive integer n, find the pivot integer x such that:

The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
Return the pivot integer x. 

If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input.


Input: n = 8
Output: 6
Explanation: 6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.

方法一：数学推导
(1 + x) * x / 2 == (x + n) * (n - x + 1) / 2
x + x ^ 2 == xn - x^2 + x + n^2 - nx + n 

x + x^2 == x - x^2 + n + n^2
2 * x^2 == n + n^2 = n * (n + 1)
x * x = n * (n + 1) / 2

比如 n = 8, n * (n + 1) / 2 = 36
 */
class Solution {
 public:
  int pivotInteger(int n) {
    int x = sqrt(n * (n + 1) / 2);
    return x * x == n * (n + 1) / 2 ? x : -1;
  }
};
int main() {

  Solution test;
  return 0;
}