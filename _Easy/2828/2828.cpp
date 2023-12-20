
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个字符串数组 words 和一个字符串 s ，请你判断 s 是不是 words 的 首字母缩略词 。

如果可以按顺序串联 words 中每个字符串的第一个字符形成字符串 s ，则认为 s 是 words 的首字母缩略词。例如，"ab" 可以由 ["apple", "banana"] 形成，但是无法从 ["bear", "aardvark"] 形成。

如果 s 是 words 的首字母缩略词，返回 true ；否则，返回 false 。

 */
class Solution {
 public:
  bool isAcronym(vector<string>& words, string s) {
    int n = words.size();
    if (n != s.size()) {
      return false;
    }
    for (int i = 0; i < n; i++) {
      if (s[i] != words[i][0]) {
        return false;
      }
    }
    return true;
  }
};
int main() {

  Solution test;
  return 0;
}