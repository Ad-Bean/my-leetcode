#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution {
 public:
  int minimumOperationsToMakeEqual(int x, int y) {
    int dif = abs(x - y);
    if (dif == 0) {
      return dif;
    }
    int xx = max(x, y), yy = min(x, y);
  }
};
int main() {

  Solution test;
  return 0;
}