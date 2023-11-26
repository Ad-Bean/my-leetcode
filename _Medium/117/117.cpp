#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
BFS On, On
queue<Node*> que;
que.emplace(root);
while (!que.empty()) {
    int sz = que.size();
    for (int i = 0; i < sz - 1; i++) {
    Node* front = que.front();
    que.pop();
    front->next = que.front();
    if (front->left)
        que.emplace(front->left);
    if (front->right)
        que.emplace(front->right);
    }
    Node* front = que.front();
    que.pop();
    front->next = nullptr;
    if (front->left)
    que.emplace(front->left);
    if (front->right)
    que.emplace(front->right);
}

Linked List On O1
建立某一层 next 再遍历，就不用使用队列
void handle(Node*& last, Node*& curr, Node*& next) 

如果 last 非 nullptr，表示 last 和 curr 在同一层，last->next = curr
如果 next 是 nullptr，表示 next 是下一层开始，next = curr 赋值
每次更新 last = curr

从 root 开始
左子树既是 next 也是 last，对右子树，更新 last->next 和 last
循环往复，每次找到最左的，即是 next，也是 last
*/

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;
  Node() : val(0), left(NULL), right(NULL), next(NULL) {}
  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
  Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
  void handle(Node*& last, Node*& curr, Node*& next) {
    if (last) {
      last->next = curr;
    }
    if (!next) {
      next = curr;
    }
    last = curr;
  }

 public:
  Node* connect(Node* root) {
    if (!root) {
      return nullptr;
    }
    Node* curr = root;
    while (curr) {
      Node *last = nullptr, *next = nullptr;
      for (Node* p = curr; p != nullptr; p = p->next) {
        if (p->left) {
          handle(last, p->left, next);
        }
        if (p->right) {
          handle(last, p->right, next);
        }
      }
      curr = next;
    }
    return root;
  }
};
int main() {

  Solution test;
  return 0;
}