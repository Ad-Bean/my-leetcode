
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你两个字符串 haystack 和 needle ，
请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。

如果 needle 不是 haystack 的一部分，则返回  -1 。 

方法一：KMP 时间复杂度 O(n + m) 空间复杂度 O(m)
对于普通的 On^2 暴力匹配
KMP 可以在不匹配的时候不需要完全后退
ABABABC
ABABC
此时 C 不匹配，但是子串 ABAB 相同，可以直接从第二个 AB 开始匹配

next 数组：表示可以跳过匹配的字符个数
ABABC
00120

查找：
i = j = 0 // 主串子串指针
while (i < n) {
    if (s[i] == t[j]) {i++, j++;}        // 匹配相同
    else if (j > 0) { j = next[j - 1]; } // 匹配失败跳过前几个
    else { i++; }                        // 子串 t[0] 匹配失败
    if (j == m) { return i - j; }        // 匹配成功
}

next 数组：实际上是子串中，共同前后缀的长度 (最长且不是本身)
ABABC
对 A 没有
对 AB 没有
对 ABA 有 A 共同前后缀
对 ABAB 有 AB
对 ABABC 没有

生成 next 数组算法：递推
如果当前共同前后缀长度为 x 如果下一个字符相同则 x+1，不同则在左边重新开始

next = [0]  // next 数组
len = 0;    // 当前共同前后缀长度
i = 1;
while (i < m) {
    if (t[len] == t[i]) {         // 前后缀相同
        len++;
        next.emplace_back(len);
        i++;
    } else {                      // 前后缀不同
        if (len == 0) {
            next.emplace_back(0); // 没有相同前后缀
            i++;
        } else {
            len = next[len - 1];  // 回到前一个最长共同前后缀
        }
    }
}
*/
class Solution {
 public:
  int strStr(string haystack, string needle) {
    int n = haystack.size(), m = needle.size();
    vector<int> next;
    next.emplace_back(0);
    int i = 1, len = 0;  // 下标和最长共同前后缀
    while (i < m) {
      if (needle[i] == needle[len]) {
        next.emplace_back(++len);
        i++;
      } else {
        if (len == 0) {
          i++;
          next.emplace_back(0);
        } else {
          len = next[len - 1];
        }
      }
    }

    int j = 0;
    i = 0;
    while (i < n) {
      if (haystack[i] == needle[j]) {
        i++, j++;
      } else if (j > 0) {
        j = next[j - 1];
      } else {
        i++;
      }
      if (j == m) {
        return i - j;
      }
    }
    return -1;
  }
};
int main() {

  Solution test;
  return 0;
}