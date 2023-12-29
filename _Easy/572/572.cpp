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

方法一：dfs
暴力：dfs root 中的每个结点，判断从该店开始是否和 subRoot 相等
return check(node, sub) || dfs(node->left, sub) || dfs(node->right, sub)

方法二：串匹配
将 root 和 subroot 转成深度优先序列（先序），检查 sub 是不是 root 的子串
正确性：可能不正确，需要引入 lnull rnull

可以使用暴力匹配 或者 KMP

方法三：树哈希
考虑把每个子树都映射成一个唯一的数，如果 t 对应的数字和 s 中任意一个子树映射的数字相等，
则 t 是 s 的某一棵子树。

哈希函数：fo = vo + 31 * f_l * p(s_l) + 179 * f_r * p(s_r)
https://leetcode.cn/problems/subtree-of-another-tree/solutions/233896/ling-yi-ge-shu-de-zi-shu-by-leetcode-solution/
*/
class Solution {
  bool check(TreeNode* l, TreeNode* r) {
    if (!l && !r) {
      return true;
    }
    if ((!l && r) || (l && !r) || (l->val != r->val)) {
      return false;
    }
    return check(l->left, r->left) && check(l->right, r->right);
  }
  bool dfs(TreeNode* node, TreeNode* sub) {
    if (!node) {
      return false;
    }
    return check(node, sub) || dfs(node->left, sub) || dfs(node->right, sub);
  }

 public:
  bool isSubtree(TreeNode* root, TreeNode* subRoot) { return dfs(root, subRoot); }
};

int main() {

  Solution test;
  return 0;
}