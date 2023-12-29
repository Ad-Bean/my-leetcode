#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
  vector<int> s, t;
  int maxE, lnull, rnull;

  void getMaxElement(TreeNode* o) {
    if (!o) {
      return;
    }
    maxE = max(maxE, o->val);
    getMaxElement(o->left);
    getMaxElement(o->right);
  }

  void getDfsOrder(TreeNode* o, vector<int>& tar) {
    if (!o) {
      return;
    }
    tar.emplace_back(o->val);
    if (o->left) {
      getDfsOrder(o->left, tar);
    } else {
      tar.emplace_back(lnull);
    }
    if (o->right) {
      getDfsOrder(o->right, tar);
    } else {
      tar.emplace_back(rnull);
    }
  }

  bool KMP() {
    int n = s.size(), m = t.size();
    vector<int> next(m, -1);
    for (int i = 1, j = -1; i < m; i++) {
      while (j != -1 && t[i] != t[j + 1]) {
        j = next[j];
      }
      if (t[i] == t[j + 1]) {
        ++j;
      }
      next[i] = j;
    }
    for (int i = 0, j = -1; i < n; i++) {
      while (j != -1 && s[i] != t[j + 1]) {
        j = next[j];
      }
      if (s[i] == t[j + 1]) {
        ++j;
      }
      if (j == m - 1) {
        return true;
      }
    }
    return false;
  }

 public:
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    maxE = INT_MIN;
    getMaxElement(root);
    getMaxElement(subRoot);
    lnull = maxE + 1;
    rnull = maxE + 2;
    getDfsOrder(root, s);
    getDfsOrder(subRoot, t);
    return KMP();
  }
};
int main() {

  Solution test;
  return 0;
}