#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
一个双端队列满足 pushFront, popFront 和 pushBack, popBack
两个双端队列满足 pushMiddle, popMiddle

pushMiddle:
if (left.size() == right.size()) {
    right.pushFront(val)
} else if (left.size() < right.size()) {
    left.pushBack(val)
}

popMiddle:
if (left.size() == right.size()) {
    return left.popBack()
} else if (left.size() < right.size()) {
    return right.popFront()
}

为了维持中间点是 middle（保证 left.size() == right.size() - 1 or left.size() == right.size()），需要修改 pushFront 和 popFront
left.pushFront()
if (left.size() > right.size()) {
    int m = left.popBack()
    right.pushback(m)
}

left.popFront()
if (left.size() < right.size() - 1) {
    int m = right.popFront()
    left.pushback(m)
}




 */
class FrontMiddleBackQueue {
  deque<int> l, r;

  void balance() {
    if (l.size() > r.size()) {
      r.push_front(l.back());
      l.pop_back();
      //   这辈子别写 l.size() < r.size() - 1，比较中不要出现 负一 和 size() 同时出现
      // size_t 是 unsigned 会把 -1 转成无符号，导致是无限大的数
    } else if (l.size() + 1 < r.size()) {
      l.push_back(r.front());
      r.pop_front();
    }
  }

 public:
  FrontMiddleBackQueue() {}

  void pushFront(int val) {
    l.push_front(val);
    balance();
  }

  void pushMiddle(int val) {
    if (l.size() < r.size()) {
      l.push_back(val);
    } else {
      r.push_front(val);
    }
  }

  void pushBack(int val) {
    r.push_back(val);
    balance();
  }

  int popFront() {
    if (r.empty()) {  // first push front, l.empty() r.size() == 1
      return -1;
    }
    int val = -1;
    if (l.empty()) {
      val = r.front();
      r.pop_front();
    } else {
      val = l.front();
      l.pop_front();
    }
    balance();
    return val;
  }

  int popMiddle() {

    if (r.empty()) {  // 整个队列为空
      return -1;
    }
    int val = -1;
    if (l.size() == r.size()) {
      val = l.back();
      l.pop_back();
    } else {
      val = r.front();
      r.pop_front();
    }

    return val;
  }

  int popBack() {
    if (r.empty()) {
      return -1;
    }
    int val = r.back();
    r.pop_back();
    balance();
    return val;
  }
};

int main() {
  FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
  obj->pushFront(1);
  obj->pushBack(2);
  obj->pushMiddle(3);
  obj->pushMiddle(4);
  int param_4 = obj->popFront();
  int param_5 = obj->popMiddle();
  int param_6 = obj->popBack();
  return 0;
}