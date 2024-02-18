/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode.cn/problems/binary-tree-postorder-traversal/description/
 *
 *
 * 给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。
 * 
 * 提示：
 * 
 * 树中节点的数目在范围 [0, 100] 内
 * -100 <= Node.val <= 100
 * 
 * 
 * 进阶：递归算法很简单，你可以通过迭代算法完成吗？
 * 
 * 方法一：递归
 * 左右根
 * 
 * 方法二：迭代
 * 用栈模拟递归
 * 先序：中左右，入栈顺序是右左，出栈顺序就是左右
 * 后序：左右中，入栈顺序是写中，入左右，最后反转就是后序。因为一开始写的全是中，然后栈顶
 * 
 * https://leetcode.cn/problems/binary-tree-postorder-traversal/solutions/367420/bang-ni-dui-er-cha-shu-bu-zai-mi-mang-che-di-chi-t/
 */

//  Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// @lc code=start
class Solution {
 public:
  void postorder(TreeNode* root, vector<int>& res) {
    if (root == nullptr) {
      return;
    }
    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->val);
  }

  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    postorder(root, res);
    return res;
  }
};
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode*> stk;
    vector<int> ans;
    if (root == nullptr) {
      return ans;
    }
    stk.emplace(root);
    while (!stk.empty()) {
      auto top = stk.top();
      stk.pop();
      ans.emplace_back(top->val);
      if (top->left) {
        stk.emplace(top->left);
      }
      if (top->right) {
        stk.emplace(top->right);
      }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
// @lc code=end
