#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
    int n = heights.size();
    vector<vector<int>> events;
    for (auto& query : queries) {
      events.push_back({query[0], query[1], heights[query[0]] - heights[query[1]]});
    }

    sort(events.begin(), events.end(), [](const auto& a, const auto& b) { return a[2] < b[2]; });
    vector<int> result(queries.size(), -1);
    vector<int> indices;
    for (int i = 0; i < events.size(); i++) {
      auto event = events[i];
      if (event[2] > 0) {
        result[i] = event[2];
      } else {
        indices.push_back(event[0]);
        // result[event[0]] = event[1];
      }

      int target = event[0] + 1;
      auto it = lower_bound(indices.rbegin(), indices.rend(), target);
      if (it != indices.rend()) {
        result[event[0]] = *it;
      }
    }

    return result;
  }
};

int main() {
  Solution solution;
  // 示例 1
  vector<int> heights1 = {6, 4, 8, 5, 2, 7};
  vector<vector<int>> queries1 = {{0, 1}, {0, 3}, {2, 4}, {3, 4}, {2, 2}};
  vector<int> result1 = solution.leftmostBuildingQueries(heights1, queries1);
  cout << "Result 1: ";
  for (int val : result1) {
    cout << val << " ";
  }
  cout << endl;

  // 示例 2
  vector<int> heights2 = {5, 3, 8, 2, 6, 1, 4, 6};
  vector<vector<int>> queries2 = {{0, 7}, {3, 5}, {5, 2}, {3, 0}, {1, 6}};
  vector<int> result2 = solution.leftmostBuildingQueries(heights2, queries2);
  cout << "Result 2: ";
  for (int val : result2) {
    cout << val << " ";
  }
  cout << endl;
  return 0;
}