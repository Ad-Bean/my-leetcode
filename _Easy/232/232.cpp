#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 

请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

实现 MyQueue 类：

void push(int x) 将元素 x 推到队列的末尾
int pop() 从队列的开头移除并返回元素
int peek() 返回队列开头的元素
boolean empty() 如果队列为空，返回 true ；否则，返回 false
说明：

你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
 
 
方法一：双栈模拟
stk1, stk2
push: stk1.empalce(x)
pop: 如果 stk2 栈空，stk1 全部移入 stk2，此时 stk2 栈顶是队首
 
 */
class MyQueue {
  stack<int> stk1, stk2;

 public:
  MyQueue() {}

  void push(int x) { stk1.emplace(x); }

  int pop() {
    if (stk2.empty()) {
      while (!stk1.empty()) {
        stk2.emplace(stk1.top());
        stk1.pop();
      }
    }
    int x = stk2.top();
    stk2.pop();
    return x;
  }

  int peek() {
    if (stk2.empty()) {
      if (stk2.empty()) {
        while (!stk1.empty()) {
          stk2.emplace(stk1.top());
          stk1.pop();
        }
      }
    }
    return stk2.top();
  }

  bool empty() { return stk1.empty() && stk2.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
int main() {

  Solution test;
  return 0;
}
