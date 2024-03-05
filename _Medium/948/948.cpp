#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
你的初始 能量 为 power，初始 分数 为 0，只有一包令牌以整数数组 tokens 给出。
其中 tokens[i] 是第 i 个令牌的值（下标从 0 开始）。

你的目标是通过有策略地使用这些令牌以 最大化 总 分数。在一次行动中，
你可以用两种方式中的一种来使用一个 未被使用的 令牌（但不是对同一个令牌使用两种方式）：

朝上：如果你当前 至少 有 tokens[i] 点 能量 ，可以使用令牌 i ，失去 tokens[i] 点 能量 ，并得到 1 分 。
朝下：如果你当前至少有 1 分 ，可以使用令牌 i ，获得 tokens[i] 点 能量 ，并失去 1 分 。
在使用 任意 数量的令牌后，返回我们可以得到的最大 分数 。
输入：tokens = [100], power = 50
输出：0
解释：因为你的初始分数为 0，无法使令牌朝下。你也不能使令牌朝上因为你的能量（50）比 tokens[0] 少（100）。

输入：tokens = [200,100], power = 150
输出：1
解释：使令牌 1 正面朝上，能量变为 50，分数变为 1 。
不必使用令牌 0，因为你无法使用它来提高分数。可得到的最大分数是 1。

方法一：贪心 + 排序
初始积分 0，所以一开始用 power 换积分，然后用积分换不够的

首先排序，只要 power 够，就一直 power -= token[i]，积分加 1

一旦积分够了就去换 power，一旦 power 不够了就去换积分

写法上：
如果用 while (l <= r && (power >= tokens[l] || (points > 0 && l < r))) 更简洁
因为 l==r 的时候 points > 0，换 power 没有意义，需要最大化 points

否则需要求一个最大的 ans = max(ans, points)

优化：
int n = tokens.size();
sort(tokens.begin(), tokens.end());
if (n == 0 || power < tokens[0]) {
    return 0;
}
 */
class Solution {
 public:
  int bagOfTokensScore(vector<int>& tokens, int power) {
    int n = tokens.size();
    sort(tokens.begin(), tokens.end());
    if (n == 0 || power < tokens[0]) {
      return 0;
    }
    int points = 0;
    int l = 0, r = n - 1;
    while (l <= r && (power >= tokens[l] || (points > 0 && l < r))) {
      // 先换积分
      while (l <= r && power >= tokens[l]) {
        power -= tokens[l++];
        points++;
      }
      // 能量不够，换能量
      if (points > 0 && l < r) {
        power += tokens[r--];
        points--;
      }
    }
    return points;
  }
};
int main() {

  Solution test;
  return 0;
}
