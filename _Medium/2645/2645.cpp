#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个字符串 word ，你可以向其中任何位置插入 "a"、"b" 或 "c" 任意次，返回使 word 有效 需要插入的最少字母数。

如果字符串可以由 "abc" 串联多次得到，则认为该字符串 有效 。

示例 1：

输入：word = "b"
输出：2
解释：在 "b" 之前插入 "a" ，在 "b" 之后插入 "c" 可以得到有效字符串 "abc" 。
示例 2：

输入：word = "aaa"
输出：6
解释：在每个 "a" 之后依次插入 "b" 和 "c" 可以得到有效字符串 "abcabcabc" 。

方法一：双指针
假设目标是 abc 串联字符串
用 l 和 r 指针，对应 串联字符串 和 word，相同则都前进，否则计数并且移动 l 比较下一个

方法二：相邻字母
由于 abc 相邻，考虑 x 和 y 相邻，使得 s 有效则需要插入 y - x - 1 个字母
比如 ac 插入一个，ca 连续不需要插入
(y-x-1+3) % 3
并且需要考虑开头和 a 差多少，结尾和 c 差多少个：s[0]-'a' 和 结尾 'c'-s[n-1]

int ans = s[0] + 2 - s.back();
for (int i = 1; i < s.length(); i++) {
    ans += (s[i] + 2 - s[i - 1]) % 3;
}
return ans;

方法三：
假设答案由 t 个 abc 组成，那么需要插入的字符个数为 3t−n
对于相邻字符 xy
如果 x < y 则可能在一个 abc 中
如果 x >= y 则一定不在一个 abc 中，表示有一个 abc 在这之间
比如 caa 有 s[0] >= s[1], s[1] >= s[2] 则表示有 3 个 abc
int t = 1;
for (int i = 1; i < s.length(); i++) {
    t += s[i - 1] >= s[i]; // 必须生成一个新的 abc
}
return t * 3 - s.length();

 */
class Solution {
 public:
  int addMinimum(string word) {
    string t = "abc";
    int ans = 0;
    int n = word.size();
    for (int l = 0, r = 0; r < n; l = (l + 1) % 3) {
      if (word[r] != t[l]) {
        ans++;
      } else {
        r++;
      }
    }
    ans += (word[n - 1] == 'c' ? 0 : word[n - 1] != 'b' ? 1 : 2);
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}
