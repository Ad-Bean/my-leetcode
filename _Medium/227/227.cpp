#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。

整数除法仅保留整数部分。

你可以假设给定的表达式总是有效的。所有中间结果将在 [-2^31, 2^31 - 1] 的范围内。


方法一：栈
乘除优先加减，先进行乘除，然后放回原表达式，进行整个表达式运算

+: 数字入栈
-: 相反数入栈
\* /: 计算数字与 栈顶元素，替换为计算结果

如果是数字：当前 num = num * 10 + (s[i] - '0')
如果是操作符或最后一位：
之前的符号 + - 入栈当前数字正反，* / 最后一位 * / 当前数字
sign = s[i] 清空 num

最后累计栈

*/
class Solution {
 public:
  int calculate(string s) {
    vector<int> stk;
    char sign = '+';
    int num = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      if (isdigit(s[i])) {
        num = num * 10 + (s[i] - '0');
      }
      if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
        switch (sign) {
          case '+':
            stk.emplace_back(num);
            break;
          case '-':
            stk.emplace_back(-num);
            break;
          case '*':
            stk.back() *= num;
            break;
          case '/':
            stk.back() /= num;
            break;
          default:
            break;
        }
        sign = s[i];
        num = 0;
      }
    }
    return accumulate(stk.begin(), stk.end(), 0);
  }
};
int main() {

  Solution test;
  return 0;
}
