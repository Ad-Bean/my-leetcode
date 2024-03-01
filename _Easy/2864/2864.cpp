#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个 二进制 字符串 s ，其中至少包含一个 '1' 。

你必须按某种方式 重新排列 字符串中的位，使得到的二进制数字是可以由该组合生成的 最大二进制奇数 。

以字符串形式，表示并返回可以由给定组合生成的最大二进制奇数。

注意 返回的结果字符串 可以 含前导零。


输入：s = "010"
输出："001"
解释：因为字符串 s 中仅有一个 '1' ，其必须出现在最后一位上。所以答案是 "001" 。


方法一：贪心
从右往左找到第一个 1，必须放在末尾
剩下的 1 则在前面
中间的全是 0

 */
class Solution {
 public:
  string maximumOddBinaryNumber(string s) {
    int n = s.size();
    bool isOdd = false;
    string ans = string(n, '0');
    int st = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        if (!isOdd) {
          ans[n - 1] = '1';
          isOdd = true;
        } else {
          ans[st++] = '1';
        }
      }
    }
    return ans;
  }
};
int main() {

  return 0;
}
