#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个字符串 s 和一个整数 repeatLimit ，用 s 中的字符构造一个新字符串 repeatLimitedString ，
使任何字母 连续 出现的次数都不超过 repeatLimit 次。
你不必使用 s 中的全部字符。

返回 **字典序最大**的 repeatLimitedString 。

输入：s = "cczazcc", repeatLimit = 3
输出："zzcccac"
解释：使用 s 中的所有字符来构造 repeatLimitedString "zzcccac"。
字母 'a' 连续出现至多 1 次。
字母 'c' 连续出现至多 3 次。
字母 'z' 连续出现至多 2 次。
因此，没有字母连续出现超过 repeatLimit 次，字符串是一个有效的 repeatLimitedString 。
该字符串是字典序最大的 repeatLimitedString ，所以返回 "zzcccac" 。
注意，尽管 "zzcccca" 字典序更大，但字母 'c' 连续出现超过 3 次，所以它不是一个有效的 repeatLimitedString 。
 
方法一：贪心
每次选择当前剩余的字典序最大的字符加到 字符串末尾；
如果字符串末尾的字符已经连续出现了 repeatLimit 次，则将字典序次大的字符加到字符串末尾，
随后继续选择当前剩余的字典序最大的字符加到字符串末尾，直至使用完字符或没有新的字符可以合法加入。


 */
class Solution {
 public:
  string repeatLimitedString(string s, int repeatLimit) {
    vector<int> cnt(26);
    for (const char& c : s) {
      cnt[c - 'a']++;
    }
    string ans;
    int m = 0;
    for (int i = 25, j = 24; i >= 0 && j >= 0;) {
      if (cnt[i] == 0) {                   // 用完了，下一个
        m = 0;                             //
        i--;                               //
      } else if (m < repeatLimit) {        // 可以用且没超过 limit
        cnt[i]--;                          //
        ans += 'a' + i;                    //
        m++;                               //
      } else if (j >= i || cnt[j] == 0) {  // 超过 limit，找下一个替代，直到有可用的
        j--;                               //
      } else {                             //
        cnt[j]--;                          // 用下一个替代
        ans += 'a' + j;                    //
        m = 0;                             //
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}
