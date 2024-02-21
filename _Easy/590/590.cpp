#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

/*
// Definition for a Node.
*/
/* 
给定一个 n 叉树的根节点 root ，返回 其节点值的 后序遍历 。

n 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null 分隔（请参见示例）。

方法一：递归
后序遍历：左右根

方法二：迭代
二叉树后序遍历的迭代：入栈根左右，然后反转
N 叉树后序遍历的迭代：入栈根左右，然后反转
 */
class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
 public:
  vector<int> postorder(Node* root) {
    vector<int> ans;
    function<void(Node*)> dfs = [&](Node* node) {
      if (!node) {
        return;
      }
      for (const auto& child : node->children) {
        dfs(child);
      }
      ans.emplace_back(node->val);
    };
    dfs(root);
    return ans;
  }
};

class Solution {
 public:
  vector<int> postorder(Node* root) {
    vector<int> ans;
    if (!root) {
      return ans;
    }
    stack<Node*> stk;
    stk.emplace(root);
    while (!stk.empty()) {
      auto top = stk.top();
      stk.pop();
      ans.emplace_back(top->val);
      for (auto child : top->children) {
        stk.emplace(child);
      }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}
