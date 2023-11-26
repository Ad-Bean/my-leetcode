#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
 public:
  int findChampion(int n, vector<vector<int>>& edges) {
    vector<int> ind(n, 0);
    for (int i = 0; i < edges.size(); i++) {
      int v = edges[i][1];
      ind[v]++;
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
      if (ind[i] == 0) {
        if (ans == -1) {
          ans = i;
        } else {
          return -1;
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