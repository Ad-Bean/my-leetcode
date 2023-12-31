#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

方法一：辅助栈
只要存小于等于之前（辅助栈栈顶）的元素，栈底为 INT_MAX
另一种辅助栈，pair<int,int>

方法二：不用辅助栈，存差值
stack<int> stk;
min_val = -1;

void push(int val) {
    if (stk.empty()) {
        stk.emplace(0);
        min_val = val;
    } else {
        int dif = val - min_val; // 当前值减去之前最小值
        stk.emplace(dif);        // 存入差值
        min_val = dif > 0 ? min_val : val; // 如果差值大于零，即新值不是最小值，不更新；否则新值更小，更新为新值
    }
}

void pop() {
    if (!stk.empty()) {
        int dif = stk.top()         // 取出差值
        stk.pop();

        int top = min_val;    
        if (dif < 0) {             // 
            min_val = top - dif;   // 如果差值小于 0，表示更小的 min_val 被弹出，更新新的 min_val 返回之前的 min_val
        } else {
            top = min_val + dif;   // 如果差值大于 0，用差值得到正确的值
        }
        return top;
    }
}

int top() {
    return stk.top() < 0 ? min_val : stk.top() + min_val;
}

int getMin() {
    if (!stk.empty()) return min_val;
    return -1;
}

 */
class MinStack {
  stack<int> stk;
  stack<int> min_stk;

 public:
  MinStack() { min_stk.emplace(INT_MAX); }

  void push(int val) {
    stk.emplace(val);
    min_stk.emplace(min(min_stk.top(), val));
  }

  void pop() {
    stk.pop();
    min_stk.pop();
  }

  int top() { return stk.top(); }

  int getMin() { return min_stk.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main() {

  Solution test;
  return 0;
}