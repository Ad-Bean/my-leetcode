#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
 * dfs / union find
    vector<vector<int>> g(n);
    for (auto edge : edges) {
      int u = edge[0], v = edge[1];
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
*/
class Solution {
 public:
  long long countPairs(int n, vector<vector<int>>& edges) {
    vector<int> fa(n), sz(n);
    for (int i = 0; i < n; i++) {
      fa[i] = i;
      sz[i] = 1;
    }
    function<int(int)> find = [&](int x) -> int {
      return fa[x] == x ? x : fa[x] = find(fa[x]);
    };
    function<void(int, int)> unionFind = [&](int x, int y) {
      int fx = find(x), fy = find(y);
      if (fx == fy)
        return;
      if (sz[fx] > sz[fy]) {
        fa[fy] = fx;
        sz[fx] += sz[fy];
      } else {
        fa[fx] = fy;
        sz[fy] += sz[fx];
      }
    };

    for (const auto& edge : edges) {
      unionFind(edge[0], edge[1]);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      int fi = find(i);
      ans += n - sz[fi];
    }
    return ans / 2;
  }
};
int main() {

  Solution test;
  return 0;
}