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
给出一个满足下述规则的二叉树：

root.val == 0
如果 treeNode.val == x 且 treeNode.left != null，那么 treeNode.left.val == 2 * x + 1
如果 treeNode.val == x 且 treeNode.right != null，那么 treeNode.right.val == 2 * x + 2
现在这个二叉树受到「污染」，所有的 treeNode.val 都变成了 -1。

请你先还原二叉树，然后实现 FindElements 类：

FindElements(TreeNode* root) 用受污染的二叉树初始化对象，你需要先把它还原。
bool find(int target) 判断目标值 target 是否存在于还原后的二叉树中并返回结果。


方法一：DFS
用 dfs 还原二叉树
从根开始 DFS，根节点值 0，如果左子树存在，则左子树的值是 2 * x + 1，右子树的值是 2 * x + 2
时间复杂度 O(n) O(1)
空间复杂度 O(n)
方法二：位运算
由于值结点具有规律，对结点值都加 1
           1
         /   \
       10     11
      / \    /  \
    100 101 110 111

此时左结点等于父节点左移，右结点等于父节点左移加 1
对于 target，在树上查找 target + 1，可以通过从高到低，判断是向左还是向右。
比如 101 就是根节点向左 10 然后再向右 101

__builtin_clz(target + 1) 返回 target + 1的二进制表示中前导 0 的个数
int k = 30 - __builtin_clz(target + 1) 返回 target + 1 的二进制表示中最高位 1 的位置
TreeNode *cur = root
从根节点开始，如果 target + 1 & (1 << k) == 0，说明 target + 1 的第 k 位是 0，就往左走，否则往右走

时间复杂度 O(n) O(min(H, log target))
空间复杂度 O(1)
 */

class FindElements {
  unordered_set<int> st;

  void dfs(TreeNode* root, int val) {
    if (!root)
      return;
    root->val = val;
    st.insert(val);
    dfs(root->left, 2 * val + 1);
    dfs(root->right, 2 * val + 2);
  }

 public:
  FindElements(TreeNode* root) {
    dfs(root, 0);
  }

  bool find(int target) {
    return st.count(target) > 0;
  }
};
/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

int main() {

  Solution test;
  return 0;
}
