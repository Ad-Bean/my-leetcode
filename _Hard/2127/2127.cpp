#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
 public:
  int maximumInvitations(vector<int>& favorite) {
    int n = favorite.size();
    vector<int> deg(n);
    for (int f : favorite) {
      deg[f]++;
    }
    vector<vector<int>> rg(n);  // 返图
    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (deg[i] == 0) {
        q.emplace(i);
      }
    }

    while (!q.empty()) {
      int x = q.front();
      q.pop();
      // favorite[i] -> i
      int y = favorite[x];
      rg[y].emplace_back(x);
      if (--deg[y] == 0) {
        q.emplace(y);
      }
    }

    function<int(int)> rdfs = [&](int x) -> int {
      int max_depth = 1;
      for (int son : rg[x]) {
        max_depth = max(max_depth, rdfs(son) + 1);
      }
      return max_depth;
    };

    int max_ring = 0, sum_size = 0;
    for (int i = 0; i < n; i++) {
      if (deg[i] == 0)
        continue;
      deg[i] = 0;  // 避免重复访问
      int ring_size = 1;
      for (int x = favorite[i]; x != i; x = favorite[x]) {
        deg[x] = 0;
        ring_size++;
      }

      if (ring_size == 2) {
        sum_size += rdfs(i) + rdfs(favorite[i]);
      } else {
        max_ring = max(max_ring, ring_size);
      }
    }
    return max(max_ring, sum_size);
  }
};
int main() {

  Solution test;
  return 0;
}