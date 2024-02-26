#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 

给定两个整数数组，preorder 和 postorder ，其中 preorder 是一个具有 无重复 值的二叉树的前序遍历，postorder 是同一棵树的后序遍历，重构并返回二叉树。

如果存在多个答案，您可以返回其中 任何 一个。

方法一：递归
前序遍历的第一个节点是根节点，后序遍历的最后一个节点是根节点

怎么划分左右子树呢？

前序 preorder[1] 是左子树的根节点，如果为空则是右子树的根节点（后者可以把右子树已到左子树）
只考虑前者，在 postorder 中找到 preorder[1] 的位置，则左子树的节点个数为 i+1

 */

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
 public:
  TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    int n = preorder.size();
    unordered_map<int, int> val2idx;
    for (int i = 0; i < n; i++) {
      val2idx[postorder[i]] = i;
    }
    function<TreeNode*(int, int, int, int)> dfs = [&](int pre_l, int pre_r, int post_l, int post_r) -> TreeNode* {
      if (pre_l > pre_r) {
        return nullptr;
      }
      int left_sz = 0;
      if (pre_l < pre_r) {
        left_sz = val2idx[preorder[pre_l + 1]] - post_l + 1;
      }
      // 根节点，前序第一个 or 后序最后一个
      TreeNode* root = new TreeNode(preorder[pre_l]);
      // 前序第二个 左子树根节点，左子树的结点 [pre_l + 1, pre_l + left_sz]
      // 后序左子树的结点 [post_l, post_l + left_sz - 1] -1 表示去掉根节点
      root->left = dfs(pre_l + 1, pre_l + left_sz, post_l, post_l + left_sz - 1);
      // 前序左子树的结点 [pre_l + left_sz + 1, pre_r] +1 表示去掉根节点
      // 后序右子树的结点 [post_l + left_sz, post_r - 1] -1 表示去掉根节点
      root->right = dfs(pre_l + left_sz + 1, pre_r, post_l + left_sz, post_r - 1);
      return root;
    };
    return dfs(0, n - 1, 0, n - 1);
  }
};
int main() {

  Solution test;
  return 0;
}
