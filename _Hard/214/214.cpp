
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给定一个字符串 s，你可以通过在字符串 前面 添加字符将其转换为回文串。
找到并返回可以用这种方式转换的最短回文串。

示例 1：

输入：s = "aacecaaa"
输出："aaacecaaa"
示例 2：

输入：s = "abcd"
输出："dcbabcd"

方法一：O(nlogn) n<=5e4 无法通过
由于是在字符串前面加，所以是 s' + s，最长的回文字符串是 reverse(s[1:]) + s
在这个字符串中找到最短 s' 使得其是回文
|s'| < |s|
将 s 分成两部分：
- 长度 |s| - |s'| 的前缀 s1
- 长度为 |s'| 的后缀 s2

s' 的反序一定和 s2 相同，并且 s1 本身是回文
找最短的 s' 就是找最长的 s1

1. 在字符串 s 中找出一个最长的前缀 s1 回文串
2. 反序剩余部分

方法二：？？？？？？？？？？？？？？？？？
一个判断字符串是回文：反序和正序相同
暴力枚举 s1 的结束位置，计算 s1 reverse(s1) 的哈希值，如果相等则找到了一个 s 的前缀回文串
int base = 131, mod = 1e9+7;
int left = 0, right = 0, mul = 1;
int best = -1;
for (int i = 0; i < n; ++i) {
    left = ((long long)left * base + s[i]) % mod;
    right = (right + (long long)mul * s[i]) % mod;
    if (left == right) {
        best = i;
    }
    mul = (long long)mul * base % mod;
}

方法三：KMP/马拉车 时间复杂度 O(n)

 */
class Solution {
 public:
  string shortestPalindrome(string s) {
    int n = s.size();
    function<bool(int, int)> isPalindrome = [&](int l, int r) -> bool {
      while (l < r) {
        if (s[l++] != s[r--]) {
          return false;
        }
      }
      return true;
    };
    if (isPalindrome(0, n - 1)) {
      return s;
    }
    if (isPalindrome(0, n - 2)) {
      return s[n - 1] + s;
    }
    if (isPalindrome(0, n - 3)) {
      return s[n - 2] + s;
    }
    int longest = -1;
    for (int i = 0; i < n; i++) {
      if (isPalindrome(0, i)) {
        longest = i;
      }
    }
    string s_ = (longest == n - 1) ? "" : s.substr(longest + 1);
    reverse(s_.begin(), s_.end());
    return s_ + s;
  }
};

int main() {

  Solution test;
  cout << test.shortestPalindrome("aacecaaa") << endl;
  cout << test.shortestPalindrome("abcd") << endl;
  return 0;
}