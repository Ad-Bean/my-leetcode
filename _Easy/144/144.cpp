/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode.cn/problems/binary-tree-preorder-traversal/description/
 *
 *
 * 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
 * 
 * 树中节点数目在范围 [0, 100] 内
 * -100 
 * 
 * 
 * 进阶：递归算法很简单，你可以通过迭代算法完成吗？
 * 
 * 方法一：递归
 * ans.emplace_back(node->val)
 * dfs(node->l)
 * dfs(node->r)
 * 
 * 方法二：迭代
 * 用栈模拟递归
 * stack<TreeNode*> stk;
 * vector<int> ans;
 * stk.emplace(root);
 * while(!stk.empty()) {
 *  auto top = stk.top();
 *  stk.pop();
 *  ans.emplace_back(top->val);
 *  if (node->r) { stk.emplace(node->r); }
 *  if (node->l) { stk.emplace(node->l); }
 * }
 * 
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
// @lc code=start

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
// Definition for a binary tree node.

class Solution {

 public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    function<void(TreeNode*)> dfs = [&](TreeNode* node) {
      if (node == nullptr) {
        return;
      }
      ans.emplace_back(node->val);
      dfs(node->left);
      dfs(node->right);
    };
    dfs(root);
    return ans;
  }
};
// @lc code=end
class Solution {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    if (!root) {
      return {};
    }
    vector<int> ans;
    stack<TreeNode*> stk;
    stk.emplace(root);
    while (!stk.empty()) {
      auto top = stk.top();
      stk.pop();
      ans.emplace_back(top->val);
      if (top->right) {
        stk.emplace(top->right);
      }
      if (top->left) {
        stk.emplace(top->left);
      }
    }
    return ans;
  }
};