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

给你一棵二叉树的根节点 root ，二叉树中节点的值 互不相同 。
另给你一个整数 start 。在第 0 分钟，感染 将会从值为 start 的节点开始爆发。

每分钟，如果节点满足以下全部条件，就会被感染：

节点此前还没有感染。
节点与一个已感染节点相邻。
返回感染整棵树需要的分钟数。

方法一：BFS + DFS
先用 DFS 求出每个节点的父节点，以及起始结点
从起点开始 BFS
 */

class Solution {
 public:
  int amountOfTime(TreeNode* root, int start) {
    TreeNode* st = root;
    unordered_map<TreeNode*, TreeNode*> parents;
    function<void(TreeNode*, TreeNode*)> dfs = [&](TreeNode* node, TreeNode* parent) -> void {
      if (!node) {
        return;
      }
      if (node->val == start) {
        st = node;
      }
      parents[node] = parent;
      dfs(node->left, node);
      dfs(node->right, node);
    };
    dfs(root, nullptr);
    int ans = -1;
    unordered_map<TreeNode*, bool> vis;
    vis[st] = true;
    queue<TreeNode*> q;
    q.emplace(st);
    while (!q.empty()) {
      ans++;
      int sz = q.size();
      for (int i = 0; i < sz; i++) {
        auto cur = q.front();
        q.pop();
        if (cur->left && !vis[cur->left]) {
          vis[cur->left] = true;
          q.emplace(cur->left);
        }
        if (cur->right && !vis[cur->right]) {
          vis[cur->right] = true;
          q.emplace(cur->right);
        }
        if (parents[cur] && !vis[parents[cur]]) {
          vis[parents[cur]] = true;
          q.emplace(parents[cur]);
        }
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}
