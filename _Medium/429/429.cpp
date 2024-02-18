#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
 public:
  vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans;
    if (!root) {
        return ans;
    }
    queue<Node*> q;
    q.emplace(root);
    while (!q.empty()) {
      int sz = q.size();
      vector<int> level;
      for (int i = 0; i < sz; i++) {
        auto node = q.front();
        q.pop();
        level.emplace_back(node->val);
        if (!node->children.empty()) {
          for (const auto& child : node->children) {
            q.emplace(child);
          }
        }
      }
      ans.emplace_back(level);
    }
    return ans;
  }
};

int main() {

  Solution test;
  return 0;
}
