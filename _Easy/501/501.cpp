#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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
  vector<int> ans;
  int base, count, maxCount;
  void update(int x) {
    if (x == base) {
      ++count;
    } else {
      count = 1;
      base = x;
    }

    if (count == maxCount) {
      ans.emplace_back(base);
    }

    if (count > maxCount) {
      maxCount = count;
      ans = vector<int>{base};
    }
  }
  void dfs(TreeNode* root) {
    if (!root) {
      return;
    }

    dfs(o->left);
    update(o->val);
    dfs(o->right);
  }

 public:
  vector<int> findMode(TreeNode* root) {
    // dfs(root);
    // return ans;
    TreeNode *cur = root, *pre = nullptr;
    while (cur) {
      if (!cur->left) {
        update(cur->val);
        cur = cur->right;
        continue;
      }
      pre = cur->left;
      while (pre->right && pre->right != cur) {
        pre = pre->right;
      }
      if (!pre->right) {
        pre->right = cur;
        cur = cur->left;
      } else {
        pre->right = nullptr;
        update(cur->val);
        cur = cur->right;
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}