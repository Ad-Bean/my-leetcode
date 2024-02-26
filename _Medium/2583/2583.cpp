#include <bits/stdc++.h>
using namespace std;

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
给你一棵二叉树的根节点 root 和一个正整数 k 。

树中的 层和 是指 同一层 上节点值的总和。

返回树中第 k 大的层和（不一定不同）。如果树少于 k 层，则返回 -1 。

注意，如果两个节点与根节点的距离相同，则认为它们在同一层。

 */
typedef long long ll;
class Solution {
 public:
  long long kthLargestLevelSum(TreeNode* root, int k) {
    if (!root) {
      return 0;
    }
    vector<ll> level_sum;
    queue<TreeNode*> q;
    q.emplace(root);
    while (!q.empty()) {
      int sz = q.size();
      ll cur = 0;
      for (int i = 0; i < sz; i++) {
        auto node = q.front();
        q.pop();
        cur += node->val;
        if (node->left) {
          q.emplace(node->left);
        }
        if (node->right) {
          q.emplace(node->right);
        }
      }
      level_sum.emplace_back(cur);
    }
    if (level_sum.size() < k) {
      return -1;
    }
    sort(level_sum.begin(), level_sum.end());
    return level_sum[level_sum.size() - k];
  }
};
int main() {

  Solution test;
  return 0;
}
