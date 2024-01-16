#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

/* 
给你两个数字字符串 num1 和 num2 ，以及两个整数 max_sum 和 min_sum 。如果一个整数 x 满足以下条件，我们称它是一个好整数：

num1 <= x <= num2
min_sum <= digit_sum(x) <= max_sum.
请你返回好整数的数目。答案可能很大，请返回答案对 1e9 + 7 取余后的结果。

注意，digit_sum(x) 表示 x 各位数字之和。

输入：num1 = "1", num2 = "12", min_num = 1, max_num = 8
输出：11
解释：总共有 11 个整数的数位和在 1 到 8 之间，分别是 1,2,3,4,5,6,7,8,10,11 和 12 。所以我们返回 11 。

1 <= num1 <= num2 <= 1e22
1 <= min_sum <= max_sum <= 400

方法一：数位 dp
dfs(i, sum, lolimit, hilimit)
dp[i][sum]
sum 最大是 400

cnt = (cnt + dfs(i + 1, sum + d, lolimit && d == lo, hilimit && d == hi)) % mod;
*/

class Solution {
 public:
  int count(string num1, string num2, int min_sum, int max_sum) {
    const int mod = 1e9 + 7;
    int n = num1.size(), m = num2.size();
    num1 = string(m - n, '0') + num1;  // 前导 0

    vector<vector<int>> memo(m, vector<int>(max_sum + 1, -1));
    function<int(int, int, bool, bool)> dfs = [&](int i, int sum, bool lolimit, bool hilimit) -> int {
      if (sum > max_sum) {
        return 0;
      }
      if (i == m) {
        return sum >= min_sum;
      }
      if (!lolimit && !hilimit && memo[i][sum] != -1) {
        return memo[i][sum];
      }
      int cnt = 0;
      int lo = lolimit ? num1[i] - '0' : 0;
      int hi = hilimit ? num2[i] - '0' : 9;
      for (int d = lo; d <= hi; d++) {
        cnt = (cnt + dfs(i + 1, sum + d, lolimit && d == lo, hilimit && d == hi)) % mod;
      }
      if (!lolimit && !hilimit) {
        memo[i][sum] = cnt;
      }
      return cnt;
    };
    return dfs(0, 0, true, true);
  }
};
int main() {

  Solution test;
  cout << test.count("4179205230", "7748704426", 8, 46) << endl;
  return 0;
}
