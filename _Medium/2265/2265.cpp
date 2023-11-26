#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/**
 * Definition for a binary tree node. */
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
 public:
  int averageOfSubtree(TreeNode* root) {
    int ans = 0;
    function<vector<int>(TreeNode*)> dfs = [&](TreeNode* node) {
      int sum = node->val, cnt = 1;
      if (node->left) {
        vector<int> ret = dfs(node->left);
        sum += ret[0];
        cnt += ret[1];
      }
      if (node->right) {
        vector<int> ret = dfs(node->right);
        sum += ret[0];
        cnt += ret[1];
      }
      if (node->val == (sum / cnt)) {
        ans++;
      }
      return vector<int>{sum, cnt};
    };
    dfs(root);
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}