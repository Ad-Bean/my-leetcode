
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 

给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。

注意:不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。
s 由数字、'+'、'-'、'('、')'、和 ' ' 组成

方法一：括号展开 + 栈
用整数记录当前符号，遇到 - 开头则翻转
用 stack 存操作符，对于 1+2+(3-(4+5))
- 扫描 1+2，栈顶 +1
- 扫描 1+2+(3 包含括号且前面符号 +，栈顶是 +1
- 扫描 1+2+(3-(4 ，当前位置被两个括号包含，+ 和 -，合并之后为 -


 */
class Solution {
 public:
  int calculate(string s) {

    stack<int> stk;
    stk.emplace(1);
    int sign = 1;
    int ret = 0;
    int n = s.length();
    for (int i = 0; i < n;) {
      if (s[i] == ' ') {
        i++;
      } else if (s[i] == '+') {
        sign = stk.top();
        i++;
      } else if (s[i] == '-') {
        sign = -stk.top();
        i++;
      } else if (s[i] == '(') {
        stk.emplace(sign);
        i++;
      } else if (s[i] == ')') {
        stk.pop();
        i++;
      } else {
        long num = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
          num = num * 10 + (s[i] - '0');
          i++;
        }
        ret += sign * num;
      }
    }
    return ret;
  }
};
int main() {

  Solution test;
  return 0;
}