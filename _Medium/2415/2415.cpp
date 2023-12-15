
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一棵 完美 二叉树的根节点 root ，请你反转这棵树中每个 奇数 层的节点值。

例如，假设第 3 层的节点值是 [2,1,3,4,7,11,29,18] ，那么反转后它应该变成 [18,29,11,7,4,3,1,2] 。
反转后，返回树的根节点。

完美 二叉树需满足：二叉树的所有父节点都有两个子节点，且所有叶子节点都在同一层。

节点的 层数 等于该节点到根节点之间的边数。

方法一：BFS
最简单的方法：交换值而不是交换结点

方法二：DFS
由于该二叉树是完美二叉树，对于根节点来说，它的孩子节点为第一层节点，此时左孩子需要与右孩子需要进行反转；

当遍历每一层时，由于 root1 root2 分别指向该层两个可能需要进行值交换的节点。
根据完美二叉树的层次反转规则 即左边排第一的元素与倒数第一元素进行交换，第二个元素与倒数二个元素交换，
此时 root1 左孩子和 root2 的右孩子 swap

TreeNode* reverseOddLevels(TreeNode* root) {
    dfs(root->left, root->right, true);
    return root;
}

void dfs(TreeNode *root1, TreeNode *root2, bool isOdd) {
    if (root1 == nullptr) {
        return;
    }
    if (isOdd) {
        swap(root1->val, root2->val);
    }
    dfs(root1->left, root2->right, !isOdd);
    dfs(root1->right, root2->left, !isOdd);
}

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
  TreeNode* reverseOddLevels(TreeNode* root) {
    int curLevel = 0;
    queue<TreeNode*> que;
    que.emplace(root);
    while (!que.empty()) {
      int sz = que.size();
      vector<TreeNode*> nodes;
      for (int i = 0; i < sz; i++) {
        TreeNode* cur = que.front();
        que.pop();
        if (cur->left) {
          que.emplace(cur->left);
        }
        if (cur->right) {
          que.emplace(cur->right);
        }
        nodes.emplace_back(cur);
      }
      if (curLevel & 1) {
        int l = 0, r = sz - 1;
        while (l < r) {
          swap(nodes[l]->val, nodes[r]->val);
          l++, r--;
        }
      }
      curLevel++;
    }
    return root;
  }
};
int main() {

  Solution test;
  return 0;
}