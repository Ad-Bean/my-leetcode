/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode.cn/problems/generate-parentheses/description/
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 输入：n = 3
 * 输出：["((()))","(()())","(())()","()(())","()()()"]
 * 
 * 
 * 输入：n = 1
 * 输出：["()"]
 * 
 * 
 * 提示：
 * 
 * 1 <= n <= 8
 * 
 * 
 * 方法一：暴力 O(2^n * n)
 * DFS 生成 2^(2n) 个字符串序列，用 On 检测是否有效 - 栈
 *     cur += '(';
 *     dfs(cur, n, res);
 *     cur.pop_back();
 * 
 *     cur += ')';
 *     dfs(cur, n, res);
 *     cur.pop_back();
 * 
 * 方法二：回溯 + 剪枝 O(4^n/sqrt(n)) 卡特兰数
 * 有效时才添加括号，左括号个数 < n 添加左括号，左括号个数大于右括号个数添加右括号
 * 
 * 无需验证
 * 
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
// @lc code=start
class Solution {
  bool isValid(const string& str) {
    int l = 0;
    for (const char& c : str) {
      if (c == '(') {
        l++;
      } else {
        --l;
      }
      if (l < 0) {
        return false;
      }
    }
    return l == 0;
  }

  void dfs(string& cur, int l, int r, int n, vector<string>& res) {
    if (cur.size() == n * 2) {
      res.emplace_back(cur);
      return;
    }
    if (l < n) {
      cur += '(';
      dfs(cur, l + 1, r, n, res);
      cur.pop_back();
    }
    if (l > r) {
      cur += ')';
      dfs(cur, l, r + 1, n, res);
      cur.pop_back();
    }
  }

 public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    string cur;
    dfs(cur, 0, 0, n, res);
    return res;
  }
};
// @lc code=end
int main() {
  Solution t;
  auto ans = t.generateParenthesis(3);
  for (const auto a : ans) {
    cout << a << " ";
  }
  cout << endl;
}