#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<string, int> vis;
    unordered_set<string> ans;
    int n = s.size();
    for (int l = 0; l + 9 < n; l++) {
      string cur = s.substr(l, 10);
      if (vis[cur] == 0) {
        vis[cur]++;
      } else {
        ans.emplace(cur);
      }
    }
    vector<string> res;
    for (string ss : ans) {
      res.emplace_back(ss);
    }
    return res;
  }
};

int main() {

  Solution test;
  return 0;
}