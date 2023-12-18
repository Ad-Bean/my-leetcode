
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
二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。
同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。

路径和 是路径中各节点值的总和。

给你一个二叉树的根节点 root ，返回其 最大路径和 。

方法一：DFS

维护一个当前最大路径和 max_sum

dfs(node) 计算二叉树中一个结点的最大贡献值，以该节点为子树，为起点，寻找一条路径
叶节点的贡献： node->val 
非叶节点的贡献：node->val + max(l, r)

对于二叉树中的一个节点，该节点的最大路径和取决于 该节点的值 与 该节点的左右子节点的最大贡献值
当前节点的最大路径： max(自己，自己+左边，自己+右边，自己 + 左边 + 右边）
 */
class Solution {
 public:
  int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    function<int(TreeNode*)> dfs = [&](TreeNode* node) {
      if (!node) {
        return 0;
      }
      int l = max(dfs(node->left), 0);
      int r = max(dfs(node->right), 0);

      int val = node->val + l + r;
      maxSum = max(maxSum, val);
      return node->val + max(l, r);
    };
    dfs(root);
    return maxSum;
  }
};
int main() {

  Solution test;
  return 0;
}