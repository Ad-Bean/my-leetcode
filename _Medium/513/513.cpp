
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
给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。

假设二叉树中至少有一个节点。

方法一：BFS
BFS 直到最底层，记录每次的左节点，然后如果下一层为空则返回

方法二：DFS
记录深度，当前深度
每次深度++，如果深度 > 当前深度，则更新当前深度
 */

class Solution {
 public:
  int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> q;
    q.emplace(root);
    int ans = -1;
    while (!q.empty()) {
      int sz = q.size();
      ans = q.front()->val;
      for (int _ = 0; _ < sz; _++) {
        auto cur = q.front();
        q.pop();
        if (cur->left) {
          q.emplace(cur->left);
        }
        if (cur->right) {
          q.emplace(cur->right);
        }
      }
      if (q.empty()) {
        return ans;
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}