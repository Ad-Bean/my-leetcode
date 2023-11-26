#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
 public:
  long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
    int n = values.size();
    vector<vector<int>> g(n);
    for (const auto& edge : edges) {
      g[edge[0]].emplace_back(edge[1]);
      g[edge[1]].emplace_back(edge[0]);
    }
    function<vector<int>(int, int)> dfs = [&](int node, int parent) -> vector<int> {
      if (g[node].size() == 0 || (g[node].szie() == 1 && g[node][0] == parent)) {
        return vector<int>{values[node], 0};
      }

      int dp0 = 0, dp1 = 0;
      for (int next : g[node]) {
        if (next != parent) {
          vector<int> dp = dfs(next, node);
          dp0 += dp[0];
          dp1 += dp[1];
        }
      }
      int cur = values[node];
      int getAll = dp0 + cur;
      int notAll = max(dp0, dp1 + cur);
      return vector<int>{getAll, notAll};
    };
    vector<int> ans = dfs(0, -1);
    return ans[1];
  }
};
int main() {

  Solution test;
  return 0;
}