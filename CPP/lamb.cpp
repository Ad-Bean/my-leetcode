#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
  int i = 0;
  // 捕获列表[]  指定函数内部可以访问的外部变量，转变为类的成员变量
  // [&] 引用捕获
  // []  值捕获（无法修改外部变量，只读）
  // [i] (int c) mutable 可以修改内部的，但不会修改外部的
  auto foo = [&](int c) {
    i++;
    cout << i << endl;
  };
  // () 参数列表
  // -> 可以省略，类型推导
  // {} 函数本题
  foo(2);
  foo(3);  // i 可以输出 1 2 但外部 i 依然是 0，闭包

  return 0;
}
