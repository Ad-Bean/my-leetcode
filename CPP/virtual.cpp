#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Base {
 public:
  virtual void func() { cout << "Base" << endl; }
};  // 晚绑定，继承类对象 指针
// 调用继承类的虚函数

class Drive : public Base {
 public:
  void func() { cout << "Drive" << endl; }
};

int main() {
  Base* p1 = new Base();
  Base* p2 = new Drive();

  p1->func();
  p2->func();  // 虚函数：调用继承类的 func
}
