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
给定两个整数数组 inorder 和 postorder ，
其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。

方法一：递归
中序遍历 左根右
后序遍历 左右根

使用 map 记录中序遍历的值到下标的映射
每次递归，in_l, in_r, post_l, post_r 表示当前子树的中序和后序的区间

当前根节点是 postorder[post_r]，在中序遍历中找到根节点的位置 in_m
左子树的长度 l_sz = in_m - in_l
左子树的中序 [in_l, in_m - 1] 后序 [post_l, post_l + l_sz - 1]
右子树的中序 [in_m + 1, in_r] 后序 [post_l + l_sz, post_r - 1]

 */

class Solution {
 public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    unordered_map<int, int> val2idx;
    for (int i = 0; i < n; i++) {
      val2idx[inorder[i]] = i;
    }
    function<TreeNode*(int, int, int, int)> dfs = [&](int in_l, int in_r, int post_l, int post_r) -> TreeNode* {
      if (in_l > in_r) {
        return nullptr;
      }
      int root_val = postorder[post_r];
      TreeNode* root = new TreeNode(root_val);
      int in_m = val2idx[root_val];
      int left_sz = in_m - in_l;
      root->left = dfs(in_l, in_m - 1, post_l, post_l + left_sz - 1);
      root->right = dfs(in_m + 1, in_r, post_l + left_sz, post_r - 1);
      return root;
    };
    TreeNode* root = dfs(0, n - 1, 0, n - 1);
    return root;
  }
};
int main() {

  Solution test;
  return 0;
}
