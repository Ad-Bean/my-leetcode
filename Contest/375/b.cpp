#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
/* 
(((a ^ b) % 10 )^ c) % d == target

先取 a ^ b 的个位

 */
class Solution {
  typedef long long ll;

  int powerModulo(int a, int b, int m) {
    int result = 1;
    a = a % m;

    while (b > 0) {
      if (b & 1) {
        result = (result * a) % m;
      }
      b = b / 2;
      a = (a * a) % m;
    }

    return result;
  }

 public:
  vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
    int n = variables.size();
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      int a = variables[i][0], b = variables[i][1], c = variables[i][2], m = variables[i][3];
      int lastDigit = powerModulo(a % 10, b, 10);
      int tt = powerModulo(lastDigit, c, m);
      if (tt == target) {
        ans.emplace_back(i);
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}