#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 

Alice 和 Bob 轮流玩一个游戏，Alice 先手。

一堆石子里总共有 n 个石子，轮到某个玩家时，他可以 移出 一个石子并得到这个石子的价值。
Alice 和 Bob 对石子价值有 不一样的的评判标准 。双方都知道对方的评判标准。

给你两个长度为 n 的整数数组 aliceValues 和 bobValues 。
aliceValues[i] 和 bobValues[i] 分别表示 Alice 和 Bob 认为第 i 个石子的价值。

所有石子都被取完后，得分较高的人为胜者。如果两个玩家得分相同，那么为平局。两位玩家都会采用 最优策略 进行游戏。

请你推断游戏的结果，用如下的方式表示：

如果 Alice 赢，返回 1 。
如果 Bob 赢，返回 -1 。
如果游戏平局，返回 0 。
 
输入：aliceValues = [1,3], bobValues = [2,1]
输出：1
解释：
如果 Alice 拿石子 1 （下标从 0开始），那么 Alice 可以得到 3 分。
Bob 只能选择石子 0 ，得到 2 分。
Alice 获胜。

方法一：贪心
假设 Alice 分数 A，Bob 分数 B
A 贪心使得 A - B > 0, B 则相反

假设 B 拿走所有石子，A 从中取，如果 A 需要赢，则贪心：使得 A-B 变得最大的 a[i] + b[i]
同样的 B 不让 A 赢，则自己也需要取可以让 A-B 变大的 a[i] + b[i]

所以 A B 轮流取 c 数组，如果是偶数则 A 取，令差值增大
但这里用一个下标数组，按照 a[i] + b[i] 降序排序更好写

 */
class Solution {
 public:
  int stoneGameVI(vector<int>& a, vector<int>& b) {
    int n = a.size();
    vector<int> c(n);
    iota(c.begin(), c.end(), 0);

    sort(c.begin(), c.end(), [&](int& i, int& j) { return a[i] + b[i] > a[j] + b[j]; });
    int dif = 0;
    for (int i = 0; i < n; i++) {
      dif += (i & 1) == 0 ? a[c[i]] : -b[c[i]];
    }
    if (dif > 0) {
      return 1;
    } else if (dif < 0) {
      return -1;
    }
    return 0;
  }
};

int main() {

  Solution test;
  return 0;
}
