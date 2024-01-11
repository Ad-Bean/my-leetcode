#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
/* 
给你三个整数 start ，finish 和 limit 。
同时给你一个下标从 0 开始的字符串 s ，表示一个 正 整数。

如果一个 正 整数 x 末尾部分是 s （换句话说，s 是 x 的 后缀），且 x 中的每个数位至多是 limit ，那么我们称 x 是 强大的 。

请你返回区间 [start..finish] 内强大整数的 **总数目** 。

如果一个字符串 x 是 y 中某个下标开始（包括 0 ），到下标为 y.length - 1 结束的子字符串，那么我们称 x 是 y 的一个后缀。比方说，25 是 5125 的一个后缀，但不是 512 的后缀。
输入：start = 1, finish = 6000, limit = 4, s = "124"
输出：5
解释：区间 [1..6000] 内的强大数字为 124 ，1124 ，2124 ，3124 和 4124 。这些整数的各个数位都 <= 4 且 "124" 是它们的后缀。注意 5124 不是强大整数，因为第一个数位 5 大于 4 。
这个区间内总共只有这 5 个强大整数。

方法一：数位 DP
数位是指把一个数字按照个、十、百、千等等一位一位地拆开，关注它每一位上的数字。
如果拆的是十进制数，那么每一位数字都是 0~9，其他进制可类比十进制。

对于 1234 枚举到 123*
对每一位讨论，如果前一位是已经达到了限制比如 3，则后一位只能在 0-highlimit 即 0-4 之间讨论，否则是 0-9
如果带上起始 100 - 6000
算上前导 0 则有 0100 到 6000，
对第一位，此时 lo = 0
对第二位，此时 lo = 1 表示前一位是最小的限制，必须从 1** 开始枚举

记忆化搜索：
vector<ll> memo(n, -1); 用于记录每一次的入参，如果讨论过则返回

 */
/* 
时间复杂度 O(nD) D = 10  n=O(log⁡finish)

基础数位 dp：下届和上届，不考虑前导 0
扩展版：考虑前导 0, dfs( is_num: bool ) -> int 
前面是否填了非 0 数字

low = str(start)
high = str(finish)
n = len(high)
low = '0' * (n - len(low)) + low # 补上前导 0 

@cache 
def dfs(i: int, limit_low: bool, limit_high: bool, is_num: bool) -> int:
  if i == n:
    return 1 if is_num else 0 # 前导0
  res = 0
  
  if not is_num:  # 前面填的全是 0, limit_low 是 True
     # 这一位可以填 0
     res += dfs(i + 1, True, False, False)
  # 请勿修改，如果对数位有约束，应该在 for 循环中限制
  lo = int(high[i]) if limit_low else 0
  hi = int(high[i]) if limit_high else 9 # 第 i 个数位可以从 lo 枚举到 hi

  d0 = 0 if is_num else 1
  if i < diff:
    for d in range(max(lo, d0), hi + 1): # 或 range(max(lo, d0), min(hi, limit) + 1) 对每一位有限制
      res += dfs(i + 1, limit_low and d == lo, limit_high and d == hi, False)
  else:
    # 必须填 int(s[i-diff])
    x = int(s[i-diff])
    if max(lo, d0) <= x <= min(hi, limit):
      res = dfs(i + 1, limit_low and d == lo, limit_high and x == hi, False)
  return res

return dfs(0, True, True, False)

 */
class Solution {
  typedef long long ll;

 public:
  long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
    string low = to_string(start);
    string high = to_string(finish);
    int n = high.size();
    low = string(n - low.size(), '0') + low;  // 前导 0
    int diff = n - s.size();                  // 前缀有几位

    vector<ll> memo(n, -1);
    function<ll(int, bool, bool)> dfs = [&](int i, bool limit_low, bool limit_high) -> ll {
      if (i == low.size()) {
        return 1;
      }
      if (!limit_low && !limit_high && memo[i] != -1) {
        return memo[i];  // 计算过
      }

      int lo = limit_low ? low[i] - '0' : 0;
      int hi = limit_high ? high[i] - '0' : 9;

      ll res = 0;
      if (i < diff) {
        for (int d = lo; d <= min(hi, limit); d++) {
          res += dfs(i + 1, limit_low && d == lo, limit_high && d == hi);
        }
      } else {
        int x = s[i - diff] - '0';  // 只能填 后缀
        if (lo <= x && x <= min(hi, limit)) {
          res = dfs(i + 1, limit_low && x == lo, limit_high && x == hi);
        }
      }

      if (!limit_low && !limit_high) {
        memo[i] = res;  // 记忆化 (i, false, false)
      }
      return res;
    };
    return dfs(0, true, true);
  }
};
int main() {

  Solution test;
  return 0;
}