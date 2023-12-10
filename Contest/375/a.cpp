#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution {
 public:
  int countTestedDevices(vector<int>& b) {
    int n = b.size();
    int cnt = 0;
    int mod = 0;
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        b[i] -= mod;
      }
      if (b[i] > 0) {
        cnt++;
        mod++;
      }
    }
    return cnt;
  }
};
int main() {

  Solution test;
  return 0;
}