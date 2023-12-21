#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

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

给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot
具有相同结构和节点值的子树。如果存在，返回 true ；否则，返回 false 。

二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。
tree 也可以看做它自身的一棵子树。
    
    
*/
class Solution {
 public:
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {}
};

int main() {

  Solution test;
  return 0;
}