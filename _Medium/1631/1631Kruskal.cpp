#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tpl;

class Solution {
 public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    int m = heights.size(), n = heights[0].size();
    vector<tpl> g;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int id = i * n + j;
        if (i > 0) {  // 从上到下
          g.emplace_back(id - n, id, abs(heights[i][j] - heights[i - 1][j]));
        }
        if (j > 0) {  // 从左到右
          g.emplace_back(id - 1, id, abs(heights[i][j] - heights[i][j - 1]));
        }
      }
    }
    sort(g.begin(), g.end(), [&](const auto& a, const auto& b) -> bool {
      auto&& [aa, aaa, aaaa] = a;
      auto&& [bb, bbb, bbbb] = b;
      return aaaa < bbbb;
    });

    vector<int> fa(m * n);
    vector<int> sz(m * n, 1);
    for (int i = 0; i < m * n; i++) {
      fa[i] = i;
    }

    function<int(int)> find = [&](int x) {
      return fa[x] == x ? x : fa[x] = find(fa[x]);
    };
    function<bool(int, int)> unite = [&](int x, int y) {
      x = find(x);
      y = find(y);
      if (x == y) {
        return false;
      }
      if (sz[x] < sz[y]) {
        swap(x, y);
      }
      fa[y] = x;
      sz[x] += sz[y];
      return true;
    };

    int ans = 0;
    for (const auto [xx, yy, w] : g) {
      unite(xx, yy);
      if (find(0) == find(m * n - 1)) {
        ans = w;
        break;
      }
    }
    return ans;
  }
};
int main() {
  //   vector<vector<int>> dirs = {{1, 2, 1, 1, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 1, 1, 2, 1}};
  vector<vector<int>> dirs = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
  Solution test;
  cout << test.minimumEffortPath(dirs) << endl;
  return 0;
}
