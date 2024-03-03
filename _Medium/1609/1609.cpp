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
如果一棵二叉树满足下述几个条件，则可以称为 奇偶树 ：

二叉树根节点所在层下标为 0 ，根的子节点所在层下标为 1 ，根的孙节点所在层下标为 2 ，依此类推。
偶数下标 层上的所有节点的值都是 奇 整数，从左到右按顺序 严格递增
奇数下标 层上的所有节点的值都是 偶 整数，从左到右按顺序 严格递减
给你二叉树的根节点，如果二叉树为 奇偶树 ，则返回 true ，否则返回 false 。

1 <= Node.val <= 1e6

方法一：BFS
层序遍历，判断奇偶性

需要注意层递增、prev 赋值

简洁写法：
int prev = level % 2 == 0 ? INT_MIN : INT_MAX;

if (level % 2 == value % 2) {
    return false;
}
if ((level % 2 == 0 && value <= prev) || (level % 2 == 1 && value >= prev)) {
    return false;
}
prev = value;

 */

class Solution {
 public:
  bool isEvenOddTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.emplace(root);
    int curLevel = 0;
    while (!q.empty()) {
      int sz = q.size();
      int prev = -1;
      for (int i = 0; i < sz; i++) {
        auto cur = q.front();
        q.pop();
        if (cur->left) {
          q.emplace(cur->left);
        }
        if (cur->right) {
          q.emplace(cur->right);
        }

        if (curLevel % 2 == 0) {
          // 偶数层，严格递增，奇数
          if (cur->val % 2 == 0) {
            return false;
          }
          if (prev == -1) {
            prev = cur->val;
          } else if (cur->val <= prev) {
            return false;
          }
        } else {
          if (cur->val % 2 == 1) {
            return false;
          }
          if (prev == -1) {
            prev = cur->val;
          } else if (cur->val >= prev) {
            return false;
          }
        }
      }

      curLevel++;
    }
    return true;
  }
};
int main() {

  Solution test;
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->right = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->right->left = new TreeNode(3);
  root->right->left = new TreeNode(7);

  cout << test.isEvenOddTree(root) << endl;
  return 0;
}
