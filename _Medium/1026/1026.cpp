
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
给定二叉树的根节点 root，找出存在于 不同 节点 A 和 B 之间的最大值 V，其中 V = |A.val - B.val|，且 A 是 B 的祖先。

（如果 A 的任何子节点之一为 B，或者 A 的任何子节点是 B 的祖先，那么我们认为 A 是 B 的祖先）

方法一：DFS
枚举祖先节点，找出所有子孙结点，计算差值，返回最大最小值

并非所有祖先节点都需要被考虑到，我们只需要获取最小的祖先节点以及最大的祖先节点。
深度优先搜索，并且记录搜索路径上的节点的最小值 lo 与最大值 hi
假设当前搜索的节点值为 val，那么与该子孙节点与它的所有祖先节点的绝对差值最大值为 
max(abs(val - lo), abs(val - hi))


 */
class Solution {
  int dfs(TreeNode* node, int lo, int hi) {
    if (!node) {
      return 0;
    }
    int dif = max(abs(node->val - lo), abs(node->val - hi));
    lo = min(lo, node->val);
    hi = max(hi, node->val);
    dif = max(dif, dfs(node->left, lo, hi));
    dif = max(dif, dfs(node->right, lo, hi));
    return dif;
  }

 public:
  int maxAncestorDiff(TreeNode* root) { return dfs(root, root->val, root->val); }
};
int main() {

  Solution test;
  return 0;
}