#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你两个长度相等的字符串 s 和 t。每一个步骤中，你可以选择将 t 中的 任一字符 替换为 另一个字符。

返回使 t 成为 s 的字母异位词的 **最小步骤数**

字母异位词 指字母相同，但排列不同（也可能相同）的字符串。

输出：s = "bab", t = "aba"
输出：1
提示：用 'b' 替换 t 中的第一个 'a'，t = "bba" 是 s 的一个字母异位词。
 
输出：s = "leetcode", t = "practice"
输出：5
提示：用合适的字符替换 t 中的 'p', 'r', 'a', 'i' 和 'c'，使 t 变成 s 的字母异位词。

输出：s = "anagram", t = "mangaar"
输出：0
提示："anagram" 和 "mangaar" 本身就是一组字母异位词。 

方法一：哈希
对 s 计数
遍历 t，如果 cnt[c]-- > 0 则忽略，否则要更改
 */
class Solution {
 public:
  int minSteps(string s, string t) {
    int cnt[26] = {};
    for (const char& c : s) {
      cnt[c - 'a']++;
    }
    int ans = 0;
    for (const char& c : t) {
      if (cnt[c - 'a'] == 0) {
        ans++;
      } else {
        cnt[cnt - 'a']--;
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}
