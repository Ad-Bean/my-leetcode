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
给定二叉搜索树的根结点 root，返回值位于范围 [low, high] 之间的所有结点的值的和。

方法一：DFS
如果当前结点满足 low <= root->val <= high，则将其加入答案，然后递归处理左右子结点。
方法二：BFS
使用队列进行层次遍历，如果当前结点满足 low <= root->val <= high，则将其加入答案，然后将其左右子结点加入队列。
 */
class Solution {
 public:
  int rangeSumBST(TreeNode* root, int low, int high) {
    function<int(TreeNode*)> dfs = [&](TreeNode* node) {
      if (node == nullptr) {
        return 0;
      }
      if (node->val >= low && node->val <= high) {
        return node->val + dfs(node->left) + dfs(node->right);
      } else if (node->val < low) {
        return dfs(node->right);
      } else {
        return dfs(node->left);
      }
    };
    return dfs(root);
  }
};
int main() {

  Solution test;
  return 0;
}
