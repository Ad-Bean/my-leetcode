/*
 * @lc app=leetcode.cn id=1457 lang=cpp
 *
 * [1457] 二叉树中的伪回文路径
 *
 * https://leetcode.cn/problems/pseudo-palindromic-paths-in-a-binary-tree/description/
 *
 *
 * 给你一棵二叉树，每个节点的值为 1 到 9 。
 * 我们称二叉树中的一条路径是 「伪回文」的，当它满足：
 * 路径经过的所有节点值的排列中，存在一个回文序列。
 * 
 * 请你返回从根到叶子节点的所有路径中 伪回文 路径的数目。
 * 
 * 
 * 提示：
 * 
 * 给定二叉树的节点数目在范围 [1, 10^5] 内
 * 1 <= Node.val <= 9
 * 
 * 方法一：DFS
 * 对于一个路径是否是回文，由于无法一边遍历一边检查
 * 所以从根节点开始深搜，如果到了叶子节点，判断当前路径是否 能组成回文
 * 
 * 由于数字都是 1 到 9，如果能组成回文有两种情况：
 * 串长偶数：每个数个数都是偶数
 * 串长奇数：只有一个数个数为基数，其他数必须偶数
 * 
 * 为了返回路径数量 需要叠加
 * 
 ! 少用 lambda 函数 dfs
 * 
 */

#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

typedef long long ll;
typedef pair<int, int> pii;

// @lc code=start
class Solution {
  int ans = 0;
  int cnt[10] = {};
  bool canPalindrome() {
    int odd = 0;
    for (const auto& i : cnt) {
      if (i & 1) {
        odd++;
      }
    }
    return odd <= 1;
  }
  void dfs(TreeNode* node) {
    if (!node) {
      return;
    }
    cnt[node->val]++;
    if (!node->left && !node->right) {  // leaf node
      // can path be palindrome? only one odd or no odd
      if (canPalindrome()) {
        ans++;
      }
    } else {
      dfs(node->left);
      dfs(node->right);
    }
    cnt[node->val]--;
  };

 public:
  int pseudoPalindromicPaths(TreeNode* root) {
    dfs(root);
    return ans;
  }
};
// @lc code=end

int main() {

  Solution test;
  return 0;
}