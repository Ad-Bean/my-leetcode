
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
中序遍历：
左根右

方法一：递归

方法二：迭代
vector<int> res;
stack<TreeNode*> stk;
while (root != nullptr || !stk.empty()) {
    while (root != nullptr) {
        stk.push(root);
        root = root->left;
    }
    root = stk.top();
    stk.pop();
    res.push_back(root->val);
    root = root->right;
}
return res;

 */
class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    function<void(TreeNode*)> inorder = [&](TreeNode* cur) {
      if (!cur) {
        return;
      }
      inorder(cur->left);
      ans.emplace_back(cur->val);
      inorder(cur->right);
    };
    inorder(root);
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}