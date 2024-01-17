#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

/* 
在 text 中找到 pattern 出现的下标
KMP 时，匹配失败不需要回退 text，只需要回退 pattern 并且尽可能少地回退，回退位置前面的一段已经匹配 text
本质就是用 text 的头部匹配 pattern 的尾部，找共同前后缀
比如 
abbaabbaaba
abbaaba

abbaab 前缀 a ab abb abba abbaa 不包含最后一个字符
abbaab 后缀 b ab aab baab bbaab 不包含第一个字符
最长共同前后缀是 ab, text 不回退时，pattern 回退到第三个字符

计算 pattern 的最长公共前后缀，
abababzababab 
a ab aba abab ababa ababab abababz abababza ...
b ab bab abab babab ababab zababab bzababab ...
对每个子字符串 [0...i]，算出其「相匹配的真前缀与真后缀中，最长的字符串的长度」
0  0  1    2    3    4       0      1 2 3 4 5 6 ?

abbaaba

 */
int main() {

  Solution test;
  return 0;
}