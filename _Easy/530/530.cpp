
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

给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。

差值是一个正数，其数值等于两值之差的绝对值。

方法一：中序遍历

二叉搜索树的中序遍历是递增序列
而一个有序数组中两两不同节点值之间的最小差值
就是相邻两个值

所以一边中序遍历一边检查相邻即可

要保证 pre 要么是引用传递，要么全局
 */

class Solution {
 public:
  int getMinimumDifference(TreeNode* root) {
    int ans = INT_MAX;
    int pre = -1;
    function<void(TreeNode*)> inorder = [&](TreeNode* node) -> void {
      if (!node) {
        return;
      }
      inorder(node->left);
      if (pre == -1) {
        pre = node->val;
      } else {
        ans = min(node->val - pre, ans);
        pre = node->val;
      }
      inorder(node->right);
    };
    inorder(root);
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}