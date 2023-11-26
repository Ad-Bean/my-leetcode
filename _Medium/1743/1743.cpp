#include <bits/stdc++.h>
using namespace std;
/* 
int n = adjacentPairs.size() + 1;
vector<int> ret(n);
for (auto& [e, adj] : mp) {
    // 找到起点
    if (adj.size() == 1) {
        ret[0] = e;
        break;
    }
}

// 起点的下一个
ret[1] = mp[ret[0]][0];
for (int i = 2; i < n; i++) {
    auto& adj = mp[ret[i - 1]]; // 找到上一个的邻接表
    ret[i] = ret[i - 2] == adj[0] ? adj[1] : adj[0];
}
return ret;


 */
typedef long long ll;
class Solution {
 public:
  vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    int n = adjacentPairs.size();
    if (n == 1) {
      return vector<int>{adjacentPairs[0][0], adjacentPairs[0][1]};
    }
    unordered_map<int, vector<int>> mp;
    for (const auto& pair : adjacentPairs) {
      int u = pair[0], v = pair[1];
      mp[u].emplace_back(v);
      mp[v].emplace_back(u);
    }

    vector<int> ans;
    queue<int> que;
    for (const auto& node : mp) {
      if (node.second.size() == 1) {
        que.emplace(node.first);
        break;
      }
    }
    unordered_map<int, bool> vis;
    while (!que.empty()) {
      int front = que.front();
      que.pop();
      vis[front] = true;
      ans.emplace_back(front);
      for (const auto& next : mp[front]) {
        if (vis[next])
          continue;
        que.emplace(next);
      }
    }
    return ans;
  }
};

int main() {

  Solution test;
  return 0;
}