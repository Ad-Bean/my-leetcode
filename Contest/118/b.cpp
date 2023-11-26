#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
 public:
  int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
    sort(hBars.begin(), hBars.end());
    sort(vBars.begin(), vBars.end());
    int hmax = 1, left = 1;
    for (int i = 0; i < hBars.size(); i++) {
      if ((i == 0 && hBars[i] == 2) || (i > 0 && hBars[i] == hBars[i - 1] + 1)) {
      } else {
        left = hBars[i] - 1;
      }
      hmax = max(hmax, hBars[i] - left + 1);
    }
    int vmax = 1;
    left = 1;
    for (int i = 0; i < vBars.size(); i++) {
      if ((i == 0 && vBars[i] == 2) || (i > 0 && vBars[i] == vBars[i - 1] + 1)) {
      } else {
        left = vBars[i] - 1;
      }
      vmax = max(vmax, vBars[i] - left + 1);
    }
    return min(vmax, hmax) * min(vmax, hmax);
  }
};

int main() {

  Solution test;
  return 0;
}