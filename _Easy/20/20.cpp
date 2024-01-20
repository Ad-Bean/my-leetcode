#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。

方法一：栈
每次有右括号，要找有无左括号能匹配

 */
class Solution {
 public:
  bool isValid(string s) {
    int n = s.size();
    if (n & 1) {
      return false;
    }

    vector<char> stk;
    unordered_map<char, char> mp = {
        {')', '('},
        {']', '['},
        {'}', '{'},
    };
    for (const char& ch : s) {
      if (mp[ch]) {
        if (stk.empty() || mp[ch] != stk.back()) {
          return false;
        } else {
          stk.pop_back();
        }
      } else {
        stk.emplace_back(ch);
      }
    }
    return stk.empty();
  }
};
int main() {

  Solution test;
  return 0;
}