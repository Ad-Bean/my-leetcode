#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
class Solution {
 public:
  int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
    double dia = 0;
    int area = 0;
    for (const auto d : dimensions) {
      int a = d[0], b = d[1];
      double dd = sqrt(1.0 * (a * a + b * b));
      if (dd > dia) {
        dia = dd;
        area = a * b;
      } else if (dd == dia) {
        area = max(a * b, area);
      }
    }
    return area;
  }
};
int main() {

  Solution test;
  vector<vector<int>> dimensions = {{6, 5}, {8, 6}, {2, 10}, {8, 1}, {9, 2}, {3, 5}, {3, 5}};
  cout << test.areaOfMaxDiagonal(dimensions) << endl;
  return 0;
}