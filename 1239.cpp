/*
 * @lc app=leetcode.cn id=1239 lang=cpp
 *
 * [1239] 串联字符串的最大长度
 *
 * https://leetcode.cn/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/
 *
 * 给定一个字符串数组 arr，字符串 s 是将 arr 的含有 不同字母 的 子序列 字符串 连接 所得的字符串。
 * 
 * 请返回所有可行解 s 中最长长度。
 * 
 * 子序列 是一种可以从另一个数组派生而来的数组，通过删除某些元素或不删除元素而不改变其余元素的顺序。
 * 
 * 
 * 方法一：01 背包
 * 考虑背包大小 26，dp[i] 表示占用 i 空间时，字符串序列集合（掩码）
 * 
 * 
 * 方法二：DFS + 位运算
 * 
 * 
 * 
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

// @lc code=start
class Solution {
  int str2bin(string& str) {
    int ret = 0;
    for (const auto& c : str) {
      if ((ret & (1 << (c - 'a')))) {  // 已占用
        return -1;
      }
      ret |= (1 << (c - 'a'));
    }
    return ret;
  }

 public:
  int maxLength(vector<string>& arr) {
    vector<vector<int>> dp(27, vector<int>());
    dp[0] = {0};
    for (auto& str : arr) {
      int len = str.size();               // 当前字符串长度
      int bin = str2bin(str);             // 字符串掩码
      if (bin == -1) {                    // 如果已经有重复的则去掉
        continue;                         //
      }                                   //
      for (int i = 26; i >= len; i--) {   //
        if (dp[i - len].size()) {         // 如果 i - len 空间存在
          for (auto& ii : dp[i - len]) {  //
            if ((ii & bin) == 0) {        // 如果没有重复
              dp[i].push_back(ii | bin);  // 拼接字符串
            }
          }
        }
      }
    }
    // 最长的字符串长度为 26
    for (int i = 26; i >= 0; i--) {
      if (dp[i].size())
        return i;
    }
    return 0;
  }
};
// @lc code=end

int main() {

  Solution test;
  //   vector<string> arr = {"un", "iq", "ue"};
  vector<string> arr = {"aa", "bb"};
  cout << test.maxLength(arr) << endl;
  return 0;
}