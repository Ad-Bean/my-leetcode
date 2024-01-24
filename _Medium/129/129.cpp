/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
 *
 * https://leetcode.cn/problems/sum-root-to-leaf-numbers/description/
 *
 *
 * 给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
 * 每条从根节点到叶节点的路径都代表一个数字：
 * 例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
 * 计算从根节点到叶节点生成的 所有数字之和 。
 * 叶节点 是指没有子节点的节点。
 * 
 * 提示：
 * 
 * 
 * 树中节点的数目在范围 [1, 1000] 内
 * 0 <= Node.val <= 9
 * 树的深度不超过 10
 * 
 * 方法一：dfs
 * dfs(node, last) {
 *   if (isLeaf) { return last * 10 + val }
 *   return dfs(node->left, last * 10 + val) + dfs(node->right, last * 10 + val)
 * }
 * 
 * 方法二：bfs
 * 维护两个队列，一个存结点，一个存对应数字
 * 根节点入队，根节点值入队
 * 
 * 每次从两个队列取出队首，
 * 如果是叶子节点，则 sum += val_que.front()
 * 如果不是叶节点，则 
 * val_que.emplace(val_que.front() * 10 + node->left->val)
 * val_que.emplace(val_que.front() * 10 + node->right->val)
 * 
 */

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

// @lc code=start
class Solution {
  int dfs(TreeNode* node, int prev) {
    if (!node) {
      return 0;
    }
    int sum = prev * 10 + node->val;
    if (!node->left && !node->right) {
      return sum;
    }

    return dfs(node->left, sum) + dfs(node->right, sum);
  }

 public:
  int sumNumbers(TreeNode* root) { return dfs(root, 0); }
};
// @lc code=end
