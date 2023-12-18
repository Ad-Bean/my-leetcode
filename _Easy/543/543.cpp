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
/* 

当前最大直径是 dfs(node->left) + dfs(node->right) + 1 

当前贡献是 max(dfs(node->left), dfs(node->right)) + 1
 */
class Solution {
 public:
  int diameterOfBinaryTree(TreeNode* root) {
    int ans = 1;
    function<int(TreeNode*)> dfs = [&](TreeNode* node) {
      if (!node) {
        return 0;
      }
      int l = dfs(node->left);
      int r = dfs(node->right);
      ans = max(ans, l + r + 1);
      return max(l, r) + 1;
    };
    dfs(root);
    return ans - 1;
  }
};

int main() {

  Solution test;
  return 0;
}
