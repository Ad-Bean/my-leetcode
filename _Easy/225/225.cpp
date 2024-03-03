#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。

实现 MyStack 类：

void push(int x) 将元素 x 压入栈顶。
int pop() 移除并返回栈顶元素。
int top() 返回栈顶元素。
boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。

方法一：双队列
队列是 FIFO 先入先出，栈是 LIFO 先入后出
使用两个队列实现栈，一个队列用于存储元素，另一个队列用于辅助操作
push: 元素 x 入队，队列 1
pop: 为了实现先入后出，将队列 1 中前 n - 1 个元素入队到队列 2


简洁写法：
每次 push 时，先加入队列 2，
再将队列 1 中的元素全部加入队列 2 （队列 1 的是旧元素，现在放队列后面，保证栈的先入后出）
然后交换队列 1 和 2，现在队列 1 最前面就是栈顶元素
此时 pop 和 top 都是队列 1 队首，empty 也是队列 1 是否为空

方法二：一个队列
int n = q.size();
q.push(x);
for (int i = 0; i < n; i++) {
    q.push(q.front());
    q.pop();
}
自己与自己交换顺序
 */
class MyStack {
  queue<int> q1, q2;

 public:
  MyStack() {}

  void push(int x) {
    if (q2.empty()) {
      q1.emplace(x);
    } else {
      q2.emplace(x);
    }
  }

  int pop() {
    if (q1.empty()) {
      while (!q2.empty()) {
        int x = q2.front();
        q2.pop();
        if (q2.empty()) {
          return x;
        }
        q1.emplace(x);
      }
    } else {
      while (!q1.empty()) {
        int x = q1.front();
        q1.pop();
        if (q1.empty()) {
          return x;
        }
        q2.emplace(x);
      }
    }
    return -1;
  }

  int top() {
    int ans = -1;
    if (q1.empty()) {
      while (!q2.empty()) {
        int x = q2.front();
        q2.pop();
        q1.emplace(x);
        if (q2.empty()) {
          ans = x;
        }
      }
    } else {
      while (!q1.empty()) {
        int x = q1.front();
        q1.pop();
        q2.emplace(x);
        if (q1.empty()) {
          return x;
        }
      }
    }
    return ans;
  }

  bool empty() { return q1.empty() && q2.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() {
  MyStack* obj = new MyStack();
  obj->push(1);
  obj->push(2);
  cout << obj->pop() << endl;
  cout << obj->top() << endl;

  return 0;
}
