/*
 * @lc app=leetcode.cn id=921 lang=cpp
 *
 * [921] 使括号有效的最少添加
 *
 * https://leetcode.cn/problems/minimum-add-to-make-parentheses-valid/description/
 *
 *
 * 只有满足下面几点之一，括号字符串才是有效的：
 * 
 * 它是一个空字符串，或者
 * 它可以被写成 AB （A 与 B 连接）, 其中 A 和 B 都是有效字符串，或者
 * 它可以被写作 (A)，其中 A 是有效字符串。
 * 
 * 
 * 给定一个括号字符串 s ，在每一次操作中，你都可以在字符串的任何位置插入一个括号
 * 
 * 例如，如果 s = "()))" ，你可以插入一个开始括号为 "(()))" 或结束括号为 "())))" 。
 * 
 * 
 * 返回 为使结果字符串 s 有效而必须添加的最少括号数。
 * 
 * 
 * 输入：s = "())"
 * 输出：1
 * 
 * 输入：s = "((("
 * 输出：3
 * 
 * 1 <= s.length <= 1000
 * s 只包含 '(' 和 ')' 字符。
 * 
 * 方法一：贪心
 * 括号匹配，用栈匹配，保证右括号和最近的左括号匹配
 * 
 * 如果遇到左括号，左括号 + 1
 * 如果遇到右括号，需要匹配
 *   如果左括号个数 > 0 则匹配，左括号个数 - 1
 *   如果左括号个数 = 0 不匹配，添加一个
 * 
 * 遍历结束后如果左括号个数 > 0 则添加多少个
 */

// @lc code=start
class Solution {
 public:
  int minAddToMakeValid(string s) {
    int left = 0, cnt = 0;
    for (const auto& ch : s) {
      if (ch == '(') {
        left++;
      } else {
        if (left > 0) {
          left--;
        } else if (left == 0) {
          cnt++;
        }
      }
    }
    if (left > 0) {
      cnt += left;
    }
    return cnt;
  }
};
// @lc code=end
