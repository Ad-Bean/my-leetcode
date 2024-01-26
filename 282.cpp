/*
 * @lc app=leetcode.cn id=282 lang=cpp
 *
 * [282] 给表达式添加运算符
 *
 * https://leetcode.cn/problems/expression-add-operators/description/
 *
 *
 * 给定一个仅包含数字 0-9 的字符串 num 和一个目标值整数 target ，在 num 的数字之间添加 二元 运算符（不是一元）+、- 或 *
 * ，返回 所有 能够得到 target 的表达式。
 * 
 * 注意，返回表达式中的操作数 不应该 包含前导零。
 * 
 * 
 * 
 * 输入: num = "123", target = 6
 * 输出: ["1+2+3", "1*2*3"] 
 * 解释: “1*2*3” 和 “1+2+3” 的值都是6。
 * 
 * 输入: num = "232", target = 8
 * 输出: ["2*3+2", "2+3*2"]
 * 解释: “2*3+2” 和 “2+3*2” 的值都是8。
 * 
 * 输入: num = "3456237490", target = 9191
 * 输出: []
 * 解释: 表达式 “3456237490” 无法得到 9191 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= num.length <= 10
 * num 仅含数字
 * -2^31 <= target <= 2^31 - 1
 * 
 * 
 * 方法一： 回溯 O(4^n)
 * n 个数字有 n-1 个空位，可以填 + , - , *, ' '
 * 用回溯模拟这个过程，从左向右并实时计算
 * 但考虑乘法的优先级，需要保存最后一个连乘串的结果
 *   
 * dfs(exp, i, res, mul) 当前表达式 exp ，第 i 个数字，res 结果， mul 最后一个连续乘法串
 * 
 * if i == n: 
 *   if res == target:
 *       ans.append(exp)
 *  return
 * 
 * 需要枚举当前表达式末尾要添加的符号 + - *
 * +: res += val 最后一个串是 val
 * -: res -= val 最后一个串是 -val
 * *: res -= mul, res += mul * val, 撤销最后串的计算结果，添加新的 mul * val
 * 
 * 方法二：DFS 搜出所有表达式然后逆波兰表达式求解 O(n*4^n) 超时
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
// @lc code=start
class Solution {
 public:
  vector<string> addOperators(string num, int target) {
    int n = num.size();
    vector<string> ans;

    function<void(string&, int, long, long)> dfs = [&](string& exp, int i, long res, long mul) {
      if (i == n) {
        if (res == target) {
          ans.emplace_back(exp);
        }
        return;
      }

      int idx = exp.size();
      if (i > 0) {
        exp.push_back(0);  // 符号位 exp[idx]
      }
      long val = 0;
      // 枚举截取的数字长度，如果是 0
      for (int j = i; j < n && (j == i || num[i] != '0'); j++) {
        val = val * 10 + num[j] - '0';
        exp.push_back(num[j]);
        if (i == 0) {
          dfs(exp, j + 1, val, val);
        } else {
          exp[idx] = '+';
          dfs(exp, j + 1, res + val, val);

          exp[idx] = '-';
          dfs(exp, j + 1, res - val, -val);

          exp[idx] = '*';
          dfs(exp, j + 1, res - mul + mul * val, mul * val);  // 撤销
        }
      }
      exp.resize(idx);  // 回溯
    };

    string exp = "";
    dfs(exp, 0, 0, 0);
    return ans;
  }
};
// @lc code=end
