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
给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。


方法一：DFS
如果两个树都为空，则两个树相同。
如果两个树中有且只有一个为空，则两个树不相同。
如果两个树的根节点的值不相同，则两个树不相同。
根据递归，递归地判断两个树的左子树是否相同，以及递归地判断两个树的右子树是否相同。
 */
class Solution {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    function<bool(TreeNode*, TreeNode*)> dfs = [&](TreeNode* a, TreeNode* b) {
      if (a == nullptr && b == nullptr)
        return true;
      if (a == nullptr || b == nullptr)
        return false;
      if (a->val != b->val)
        return false;
      return dfs(a->left, b->left) && dfs(a->right, b->right);
    };
    return dfs(p, q);
  }
};
int main() {

  Solution test;
  return 0;
}
