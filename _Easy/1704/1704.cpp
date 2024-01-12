#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个偶数长度的字符串 s 。将其拆分成长度相同的两半，前一半为 a ，后一半为 b 。

两个字符串 相似 的前提是它们都含有相同数目的元音（'a'，'e'，'i'，'o'，'u'，'A'，'E'，'I'，'O'，'U'）。
注意，s 可能同时含有大写和小写字母。

如果 a 和 b 相似，返回 true ；否则，返回 false 。
 */
class Solution {
 public:
  bool halvesAreAlike(string s) {
    unordered_map<char, bool> vowels = {{'a', true}, {'e', true}, {'i', true}, {'o', true}, {'u', true},
                                        {'A', true}, {'E', true}, {'I', true}, {'O', true}, {'U', true}};
    int n = s.size();
    int cnt1 = 0, cnt2 = 0;
    for (int l = 0, r = n / 2; l < n / 2 && r < n; l++, r++) {
      if (vowels[s[l]]) {
        cnt1++;
      }
      if (vowels[s[r]]) {
        cnt2++;
      }
    }
    return cnt1 == cnt2;
  }
};

int main() {

  Solution test;
  return 0;
}
