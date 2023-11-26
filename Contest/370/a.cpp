#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
 public:
  int findChampion(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<int> ind(n, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          ind[j]++;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (ind[i] == 0) {
        return i;
      }
    }
    return -1;
  }
};
int main() {

  Solution test;
  return 0;
}