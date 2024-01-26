/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
 *
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * 输入：digits = ""
 * 输出：[]
 * 
 * 
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 * 
 * 
 * 0 <= digits.length <= 4
 * digits[i] 是范围 ['2', '9'] 的一个数字。
 * 
 * 
 * 方法一：dfs 回溯 O(3^m * 4^n) 
 * 由于一个数字对应 3 or 4 个字母
 * 2 3 4 5 6 8 对应三个
 * 7 9 对应四个
 * 
 * 哈希表示他们的对应字母，然后 dfs
 * 
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
// @lc code=start
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    vector<string> ans;
    int n = digits.size();
    if (n == 0) {
      return ans;
    }
    const string mapping[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    function<void(int, string&)> dfs = [&](int i, string& cur) {
      if (i == n) {
        ans.emplace_back(cur);
      } else {
        string nx = mapping[digits[i] - '2'];
        for (const auto letter : nx) {
          cur.push_back(letter);
          dfs(i + 1, cur);
          cur.pop_back();
        }
      }
    };
    string cur = "";
    dfs(0, cur);
    return ans;
  }
};
// @lc code=end
