
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。

回文字符串 是正着读和倒过来读一样的字符串。

子字符串 是字符串中的由连续字符组成的一个序列。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。


方法一：中心扩展
回文串的判断方法：找到中心，左右扩展

长度为 n 的字符串会生成 2n−1 组回文中心，对应左中心 i/2 右中心 i/2 + i%2

方法二：马拉车
https://leetcode.cn/problems/palindromic-substrings/solutions/379987/hui-wen-zi-chuan-by-leetcode-solution
 */
class Solution {
 public:
  int countSubstrings(string s) {
    int ans = 0;
    int n = s.size();
    for (int i = 0; i < 2 * n - 1; i++) {
      int l = i / 2, r = i / 2 + i % 2;
      while (l >= 0 && r < n && s[l] == s[r]) {
        --l;
        ++r;
        ++ans;
      }
    }
    return ans;
  }
};

int main() {

  Solution test;
  return 0;
}