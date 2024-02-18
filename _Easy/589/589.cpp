#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给定一个 n 叉树的根节点  root ，返回 其节点值的 前序遍历 。

n 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null 分隔（请参见示例）。

方法一：递归
前序遍历：根 左 右, 对 N 叉树直接则是：根 所有孩子

方法二：迭代
使用栈模拟递归，每次出栈栈顶，加入答案，然后将孩子节点**逆序入栈**
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
  vector<int> preorder(Node* root) {
    vector<int> ans;
    function<void(Node*)> dfs = [&](Node* node) {
      if (!node) {
        return;
      }
      ans.emplace_back(node->val);
      for (const auto& child : node->children) {
        dfs(child);
      }
    };
    dfs(root);
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}
