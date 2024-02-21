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
给定两个整数数组 preorder 和 inorder ，
其中 preorder 是二叉树的先序遍历， 
inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

方法一：递归
先序遍历 根左右
中序遍历 左根右
后序遍历 左右根
中序 + 前序/后序 可以唯一确定一棵树

由于 preorder 和 inorder 均 无重复 元素，用哈希存值到下标的映射
每次递归，pre_l, pre_r, in_l, in_r 表示当前子树的前序和中序的区间
当前根节点是 preorder[pre_l]，在中序遍历中找到根节点的位置 in_m
左子树的长度 l_sz = in_m - in_l
左子树的前序 [pre_l + 1, pre_l + l_sz] 中序 [in_l, in_m - 1]
右子树的前序 [pre_l + l_sz + 1, pre_r] 中序 [in_m + 1, in_r]

递归终止：pre_l > pre_r 时返回 nullptr

方法二：迭代

 */

class Solution {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    unordered_map<int, int> val2idx;
    for (int i = 0; i < n; i++) {
      val2idx[inorder[i]] = i;
    }

    function<TreeNode*(int, int, int, int)> dfs = [&](int pre_l, int pre_r, int in_l, int in_r) -> TreeNode* {
      if (pre_l > pre_r) {
        return nullptr;
      }
      int root_val = preorder[pre_l];
      // 找到根节点在中序遍历中的位置
      int in_m = val2idx[root_val];
      TreeNode* root = new TreeNode(root_val);
      int l_sz = in_m - in_l;
      // 此时左子树的前序 [pre_l + 1, pre_l + l_sz] 中序 [in_l, in_m - 1
      root->left = dfs(pre_l + 1, pre_l + l_sz, in_l, in_m - 1);
      //   此时右子树的前序 [pre_l + l_sz + 1, pre_r] 中序 [in_m + 1, in_r]
      root->right = dfs(pre_l + l_sz + 1, pre_r, in_m + 1, in_r);
      return root;
    };
    return dfs(0, n - 1, 0, n - 1);
  }
};
int main() {

  Solution test;
  return 0;
}
