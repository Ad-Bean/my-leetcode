#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
 public:
  bool areSimilar(vector<vector<int>>& mat, int k) {
    int m = mat.size(), n = mat[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i % 2 == 0) {
          if (mat[i][j] != mat[i][(j + k) % n]) {
            return false;
          }
        } else {
          if (mat[i][j] != mat[i][(j + m - k) % n]) {
            return false;
          }
        }
      }
    }
    return true;
  }
};

int main() {
  vector<vector<int>> mat = {{1, 2, 1, 2}, {5, 5, 5, 5}, {6, 3, 6, 3}};
  int k = 2;
  Solution test;
  cout << test.areSimilar(mat, k) << endl;
  return 0;
}