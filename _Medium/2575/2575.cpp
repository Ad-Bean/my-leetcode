#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个下标从 0 开始的字符串 word ，长度为 n ，由从 0 到 9 的数字组成。另给你一个正整数 m 。

word 的 可整除数组 div  是一个长度为 n 的整数数组，并满足：

如果 word[0,...,i] 所表示的 数值 能被 m 整除，div[i] = 1
否则，div[i] = 0
返回 word 的可整除数组。

输入：word = "998244353", m = 3
输出：[1,1,0,0,0,1,1,0,0]
解释：仅有 4 个前缀可以被 3 整除："9"、"99"、"998244" 和 "9982443" 。

方法一：模运算
如果直接从左到右模拟数字，首先 1 <= n <= 1e5 最大数 10^{100000} 远超于 2^31 = 10^9
所以不能简单的每次 cur * 10 + word[i] - '0'，然后判断 cur % m == 0

对于一个数能否被 m 整数，需要取模，只需判断余数
cur = (cur * 10 + word[i] - '0') % m
在计算中取模，而不是到最后才取模

word % m = (word[:n-2] * 10 + word[n-1]) % m
         = (word[:n-2] * 10 % m + word[n-1] % m) % m
         = ((word[:n-3] % m * 10 + word[:n-2])% m + word[n-1] % m) % m
从左遍历 word，每次计算 cur = (cur * 10 + word[i] - '0') % m
*/
class Solution {
 public:
  vector<int> divisibilityArray(string word, int m) {
    long long cur = 0;
    int n = word.size();
    vector<int> div(n);
    for (int i = 0; i < n; i++) {
      cur = (cur * 10 + word[i] - '0') % m;
      if (cur == 0) {
        div[i] = 1;
      }
    }
    return div;
  }
};
int main() {

  Solution test;
  string word = "91221181269244172125025075166510211202115152121212341281327";
  cout << word.size() << endl;
  return 0;
}
