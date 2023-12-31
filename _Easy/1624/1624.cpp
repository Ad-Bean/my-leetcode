#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

/* 

给你一个字符串 s，请你返回 两个相同字符之间的最长子字符串的长度 ，计算长度时不含这两个字符。如果不存在这样的子字符串，返回 -1 。

子字符串 是字符串中的一个连续字符序列。

方法一：遍历 On

 */
class Solution {
 public:
  int maxLengthBetweenEqualCharacters(string s) {
    int n = s.size();
    int maxx = -1;
    vector<int> idx(26, -1);
    for (int i = 0; i < n; i++) {
      if (idx[s[i] - 'a'] == -1) {
        idx[s[i] - 'a'] = i;
      } else {
        maxx = max(maxx, i - idx[s[i] - 'a'] + 1);
      }
    }
    return maxx;
  }
};
int main() {

  Solution test;
  return 0;
}
