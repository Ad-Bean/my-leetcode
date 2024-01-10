#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你两个正整数 x 和 y 。

一次操作中，你可以执行以下四种操作之一：

如果 x 是 11 的倍数，将 x 除以 11 。
如果 x 是 5 的倍数，将 x 除以 5 。
将 x 减 1 。
将 x 加 1 。
请你返回让 x 和 y 相等的 最少 操作次数。

输入：x = 26, y = 1
输出：3
解释：我们可以通过以下操作将 26 变为 1 ：
1. 将 x 减 1
2. 将 x 除以 5
3. 将 x 除以 5
将 26 变为 1 最少需要 3 次操作。

方法一：BFS
典型：从 x 到 y，每个操作看作有向边，求最短路，且 x 一定能到 y
v/11, v/5, v-1, v+1
如果用 vis 记录访问过的点（数组）
如果 y >= x，只有+1操作会增加，直接返回 y - x
如果 y < x，最远距离是 x - y，但如果还有 + 1，vis 数组长度是 x + x - y + 1

优化：
vis 用数组
加边时，如果待添加的边 v/11 or v/5 or v-1 小于 y，直接更新答案 y-v+step+1

方法二：记忆化搜索
子问题：
x <= y,  x++
x >  y,  x-- 一共 x-y 次
x >  y,  x 不是 11 的倍数，比如 24，minOp(x / 11, y) + x % 11 + 1, 下一个数是 x/11 比如，要减少 x%11 次和整除
x >  y,  x 不是 11 的倍数，比如 32，minOp(x / 11 + 1, y) + 11 - x % 11 + 1, 下一个数是 x/11 + 1，要补上  11 - x%11 次和整除
x >  y,  同理

class Solution {
  unordered_map<int, int> memo;

public:
  int minimumOperationsToMakeEqual(int x, int y) {
    if (x <= y) { return y - x; }
    auto it = memo.find(x);
    if (it != memo.end()) { return it->second; } // 存在

    return memo[x] = min({
        x - y,
        minimumOperationsToMakeEqual(x / 11, y) + x % 11 + 1,
        minimumOperationsToMakeEqual(x / 11 + 1, y) + 11 - x % 11 + 1,
        minimumOperationsToMakeEqual(x / 5, y) + x % 5 + 1,
        minimumOperationsToMakeEqual(x / 5 + 1, y) + 5 - x % 5 + 1,
        });
  }
};

时间复杂度 O(log(n)^2)

 */
class Solution {
 public:
  int minimumOperationsToMakeEqual(int x, int y) {
    if (y >= x) {
      return y - x;
    }
    int ans = x - y;               // 上限
    unordered_map<int, bool> vis;  // 哈希、set、数组

    queue<int> q;
    q.emplace(x);

    int step = 0;
    while (true) {
      int sz = q.size();
      for (int i = 0; i < sz; i++) {
        int v = q.front();
        if (v == y) {
          return min(ans, step);
        }
        if (v % 11 == 0) {
          if (v / 11 < y) {
            ans = min(ans, y - v / 11 + step + 1);
          } else if (!vis[v / 11]) {
            vis[v / 11] = true;
            q.emplace(v / 11);
          }
        }
        if (v % 5 == 0) {
          if (v / 5 < y) {
            ans = min(ans, y - v / 5 + step + 1);
          } else if (!vis[v / 5]) {
            vis[v / 5] = true;
            q.emplace(v / 5);
          }
        }
        if (!vis[v + 1]) {
          vis[v + 1] = true;
          q.emplace(v + 1);
        }
        if (!vis[v - 1]) {
          vis[v - 1] = true;
          q.emplace(v - 1);
        }
        q.pop();
      }
      step++;
    }
    return step;
  }
};
int main() {

  Solution test;
  return 0;
}