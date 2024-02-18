
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 

给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。


方法一： BFS
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
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) {
      return ans;
    }
    queue<TreeNode*> q;
    q.emplace(root);
    while (!q.empty()) {
      int sz = q.size();
      vector<int> cur;
      for (int i = 0; i < sz; i++) {
        auto node = q.front();
        q.pop();
        cur.emplace_back(node->val);
        if (node->left) {
          q.emplace(node->left);
        }
        if (node->right) {
          q.emplace(node->right);
        }
      }
      ans.emplace_back(cur);
    }
    return ans;
  }
};

int main() {

  Solution test;
  return 0;
}