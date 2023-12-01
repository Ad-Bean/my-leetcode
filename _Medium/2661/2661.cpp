
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
0,0
1,1
0,1

0,1
2,0
2,1
1,1

 */
class Solution {
 public:
  int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    unordered_map<int, pair<int, int>> mp;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        mp[mat[i][j]] = {i, j};
      }
    }
    vector<int> row(m), col(n);
    for (int i = 0; i < m * n; i++) {
      int num = arr[i];
      int r = mp[num].first, c = mp[num].second;
      row[r]++;
      col[c]++;
      if (row[r] == n || col[c] == m) {
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