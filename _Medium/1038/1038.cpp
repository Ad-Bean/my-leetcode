#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//  Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
/* 
二叉搜索树
输入：[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
输出：[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

中序遍历，左中右，是有序
对每个结点，如果要求大于或者等于该节点值的所有节点值之和，就是本节点 + 右子树
采用遍历顺序：右 中 左，可以得到从右子树底向上的和
*/

class Solution {
 public:
  TreeNode* bstToGst(TreeNode* root) {
    int sum = 0;
    function<void(TreeNode*)> dfs = [&](TreeNode* node) {
      if (node == nullptr) {
        return;
      }
      dfs(node->right);
      sum += node->val;
      node->val = sum;
      dfs(node->left);
    };
    dfs(root);
    return root;
  }
};
int main() {

  Solution test;
  return 0;
}
