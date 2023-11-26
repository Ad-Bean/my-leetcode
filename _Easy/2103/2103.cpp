#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
 public:
  int countPoints(string rings) {
    int n = rings.size();
    vector<int> poles(10);
    for (int i = 0; i < n; i += 2) {
      if (rings[i] == 'R') {
        poles[rings[i + 1] - '0'] |= 0b001;
      } else if (rings[i] == 'G') {
        poles[rings[i + 1] - '0'] |= 0b010;
      } else if (rings[i] == 'B') {
        poles[rings[i + 1] - '0'] |= 0b100;
      }
    }
    int ans = 0;
    for (auto pole : poles) {
      if (pole == 0b111) {
        ans++;
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}