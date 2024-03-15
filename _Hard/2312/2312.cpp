#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
/* 
给你两个整数 m 和 n ，分别表示一块矩形木块的高和宽。
同时给你一个二维整数数组 prices ，其中 prices[i] = [hi, wi, pricei] 表
示你可以以 pricei 元的价格卖一块高为 hi 宽为 wi 的矩形木块。

每一次操作中，你必须按下述方式之一执行切割操作，以得到两块更小的矩形木块：

沿垂直方向按高度 完全 切割木块，或
沿水平方向按宽度 完全 切割木块
在将一块木块切成若干小木块后，你可以根据 prices 卖木块。你可以卖多块同样尺寸的木块。
你不需要将所有小木块都卖出去。你 不能 旋转切好后木块的高和宽。

请你返回切割一块大小为 m x n 的木块后，能得到的 最多 钱数。

注意你可以切割木块任意次。

输入：m = 3, n = 5, prices = [[1,4,2],[2,2,7],[2,1,3]]
输出：19
解释：上图展示了一个可行的方案。包括：
- 2 块 2 x 2 的小木块，售出 2 * 7 = 14 元。
- 1 块 2 x 1 的小木块，售出 1 * 3 = 3 元。
- 1 块 1 x 4 的小木块，售出 1 * 2 = 2 元。
总共售出 14 + 3 + 2 = 19 元。
19 元是最多能得到的钱数。

方法一：动态规划 / 记忆化搜索
暴力的想，贪心放满所有价值最高的木块，然后再放次高的，直到放满
但很明显这样不行，容易找到反例，并且题目限制不能旋转木块，一刀切完整
同时也可以发现子问题，垂直/水平切一刀后，得到两个子问题
横切竖切 or 竖切横切，都可以得到同一个更小的木块（重叠子问题）
高度宽度相同的两个木块，钱一致，与切出这个木块的切法无关（无后效性）
枚举所有切法，得到两块小木块的最多钱数，就知道了大木块的最多钱数（最优子结构）

f[i][j] 表示高 i 宽 j 的木块，切割后能得到最多的钱，答案 f[m][n]
如果直接售卖：f[i][j] = price
如果垂直切割：f[i][j] = max(f[i][k] + f[i][j - k]) 1 <= k <= j-1
如果水平切割：f[i][j] = max(f[k][j] + f[i - k][j]) 1 <= k <= i-1
f[i][j] = max(1,2,3)

因为 prices[i] = [hi, wi, pricei]，且 hi <= m, wi <= n 所以可以用长度 m+1 和 n+1 的二维哈希表记录价格

优化：实际上内层循环对称
f[i][j] = max(f[i][j], f[i][k] + f[i][j - k]) 1 <= k <= j/2
f[i][j] = max(f[i][j], f[k][j] + f[i - k][j]) 1 <= k <= i/2

并且可以不需要哈希表，直接用 cnt[i][j] 记录价格
 */
class Solution {
  typedef long long ll;

 public:
  long long sellingWood(int m, int n, vector<vector<int>>& prices) {
    ll f[m + 1][n + 1];
    memset(f, 0, sizeof(f));
    for (const auto& price : prices) {
      f[price[0]][price[1]] = price[2];
    }

    // 枚举所有切法
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        // 如果垂直切
        for (int k = 1; k <= j / 2; k++) {
          f[i][j] = max(f[i][j], f[i][k] + f[i][j - k]);
        }
        for (int k = 1; k <= i / 2; k++) {
          f[i][j] = max(f[i][j], f[k][j] + f[i - k][j]);
        }
      }
    }
    return f[m][n];
  }
};
int main() {

  Solution test;
  vector<vector<int>> prices = {{1, 4, 2}, {2, 2, 7}, {2, 1, 3}};
  cout << test.sellingWood(3, 5, prices) << endl;
  return 0;
}
