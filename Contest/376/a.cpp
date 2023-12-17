#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution {
 public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size();

    vector<int> mp(n * n + 1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        mp[grid[i][j]]++;
      }
    }
    vector<int> ans(2);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (mp[i * n + j + 1] == 0) {
          ans[1] = i * n + j + 1;
        }
        if (mp[i * n + j + 1] == 2) {
          ans[0] = i * n + j + 1;
        }
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}