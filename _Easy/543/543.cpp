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
给你一棵二叉树的根节点，返回该树的 直径 。

二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点 root 。

两节点之间路径的 长度 由它们之间边数表示。


方法一：dfs
由于是二叉树，从根节点开始左右最深的路径之和就是直径

当前最大直径是 dfs(node->left) + dfs(node->right) + 1 

最深的路径是 max(dfs(node->left), dfs(node->right)) + 1
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
