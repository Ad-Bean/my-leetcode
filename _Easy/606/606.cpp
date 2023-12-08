
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

// Definition for a binary tree node.
/* 
前序遍历 转换二叉树为一个括号和整数组成的字符串
空结点 ()

中左右

    1
   /\
  2 3
 /
4

输入：root = [1,2,3,4]
输出："1(2(4))(3)"
解释：初步转化后得到 "1(2(4)())(3()())" ，但省略所有不必要的空括号对后，字符串应该是"1(2(4))(3)" 。

方法一：递归
如果有两个孩子，则需要在孩子的结果外面加括号 to_string(root->val) + "(" + tree2str(root->left) + ")(" + tree2str(root->right) + ")"
如果没有孩子，则不需要加括号
如果只有左孩子，则需要  to_string(root->val) + "(" + tree2str(root->left) + ")";
如果只有右孩子，则需要 to_string(root->val) + "(" + tree2str(root->left) + ")(" + tree2str(root->right) + ")"

方法二：递推
stack

如果当前节点有两个孩子，那么我们先将右孩子入栈，再将左孩子入栈，从而保证前序遍历的顺序；
如果当前节点没有孩子，我们什么都不做；
如果当前节点只有左孩子，那么我们将左孩子入栈；
如果当前节点只有右孩子，那么需要在答案末尾添加一对 ‘()’ 表示空的左孩子，再将右孩子入栈。
 */
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
  string tree2str(TreeNode* root) {
    if (!root) {
      return "";
    }
    if (root->left == nullptr && root->right == nullptr) {
      return to_string(root->val);
    }
    if (root->right == nullptr) {
      return to_string(root->val) + "(" + tree2str(root->left) + ")";
    }
    return to_string(root->val) + "(" + tree2str(root->left) + ")(" + tree2str(root->right) + ")";
  }
};

class Solution2 {
 public:
  string tree2str(TreeNode* root) {
    string ans = "";
    stack<TreeNode*> st;
    st.push(root);
    unordered_set<TreeNode*> vis;
    while (!st.empty()) {
      auto node = st.top();
      if (vis.count(node)) {
        if (node != root) {
          ans += ")";
        }
        st.pop();
      } else {
        vis.insert(node);
        if (node != root) {
          ans += "(";
        }
        ans += to_string(node->val);
        if (node->left == nullptr && node->right != nullptr) {
          ans += "()";
        }
        if (node->right != nullptr) {
          st.push(node->right);
        }
        if (node->left != nullptr) {
          st.push(node->left);
        }
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}