
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tpl;
class Solution {
 public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m = heights.size(), n = heights[0].size();
    auto tplCmp = [](const auto& a, const auto& b) {
      auto&& [a1, a2, a3] = a;
      auto&& [b1, b2, b3] = b;
      return a3 > b3;
    };
    priority_queue<tpl, vector<tpl>, decltype(tplCmp)> hp(tplCmp);
    hp.emplace(0, 0, 0);
    vector<bool> vis(m * n);
    vector<int> dis(m * n, INT_MAX);
    dis[0] = 0;
    while (!hp.empty()) {
      auto [x, y, w] = hp.top();
      hp.pop();
      int id = x * n + y;
      if (vis[id]) {
        continue;
      }
      if (x == m - 1 && y == n - 1) {
        break;
      }
      vis[id] = true;
      for (int i = 0; i < 4; i++) {
        int nx = x + dirs[i][0], ny = y + dirs[i][1];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
          if (max(w, abs(heights[x][y] - heights[nx][ny])) < dis[nx * n + ny]) {
            dis[nx * n + ny] = max(w, abs(heights[x][y] - heights[nx][ny]));
            hp.emplace(nx, ny, dis[nx * n + ny]);
          }
        }
      }
    }
    return dis[m * n - 1];
  }
};

int main() {
  vector<vector<int>> dirs = {{1, 2, 1, 1, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 1, 1, 2, 1}};
  Solution test;
  cout << test.minimumEffortPath(dirs) << endl;
  return 0;
}
