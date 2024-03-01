#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
神奇字符串 s 仅由 '1' 和 '2' 组成，并需要遵守下面的规则：

神奇字符串 s 的神奇之处在于，串联字符串中 '1' 和 '2' 的连续出现次数可以生成该字符串。
s 的前几个元素是 s = "1221121221221121122……" 。如果将 s 中连续的若干 1 和 2 进行分组，可以得到 "1 22 11 2 1 22 1 22 11 2 11 22 ......" 。每组中 1 或者 2 的出现次数分别是 "1 2 2 1 1 2 1 2 2 1 2 2 ......" 。上面的出现次数正是 s 自身。

给你一个整数 n ，返回在神奇字符串 s 的前 n 个数字中 1 的数目。

输入：n = 6
输出：3
解释：神奇字符串 s 的前 6 个元素是 “122112”，它包含三个 1，因此返回 3 。 

方法一：双指针模拟
由于 1 和 2 必须交替出现
对于 122 
      i=2 接上 2 个 11
对于 12211
       i=3 接上 1 个 2 
对于 122112 
         i=4 接上 1 个 1
对于 1221121 
          i=5 接上 2 个 2


1 ^ 3 = 2
2 ^ 3 = 1
 */
class Solution {
 public:
  int magicalString(int n) {
    string s = "122";
    for (int i = 2; s.size() < n; i++) {
      s += string(s[i] - '0', (int(s.back() - '0') ^ 3) + '0');
    }
    return count(s.begin(), s.begin() + n, '1');
  }
};
int main() {

  Solution test;
  return 0;
}
