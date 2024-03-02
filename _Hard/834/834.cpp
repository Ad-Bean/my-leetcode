
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给定一个无向、连通的树。树中有 n 个标记为 0...n-1 的节点以及 n-1 条边 。

给定整数 n 和数组 edges ， edges[i] = [ai, bi]表示树中的节点 ai 和 bi 之间有一条边。

返回长度为 n 的数组 answer ，其中 answer[i] 是树中第 i 个节点与所有其他节点之间的距离之和。

输入: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
输出: [8,12,6,10,10,10]
解释: 树如图所示。
我们可以计算出 dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5) 
也就是 1 + 1 + 2 + 2 + 2 = 8。 因此，answer[0] = 8，以此类推。

1 <= n <= 3 * 1e4

方法一：换根 DP
暴力：枚举每个节点作为根，然后 DFS 计算距离和，时间复杂度 O(n^2)
计算以 0 为根节点的时候，得到一个距离 ans[0]
当把根换成 2 时，2 的子树距离都缩短 1，其他子树距离都增加 1，ans[2] = ans[0] + 2 - 4 = 6
所以需要计算每个子树的大小 size[i]

1. 子树大小
子树大小 = 左子树大小 + 右子树大小 + 1，后序遍历
2. DFS 保证每个节点只遍历一次
通常用 vis，但二叉树可以用 fa 结点表示父节点，如果 next == fa 就跳过
3. 换根 DP 本质，变化量很小，基于 ans[0] 算出相邻节点 2 的 ans[2]

 */
class Solution {
 public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    vector<vector<int>> g(n);
    for (const auto& e : edges) {
      auto u = e[0], v = e[1];
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }

    // 求子树大小，并且初始化 ans[0]
    vector<int> ans(n);
    vector<int> sz(n, 1);
    function<void(int, int, int)> dfs = [&](int x, int fa, int dep) {
      ans[0] += dep;  // 0 到 x 的距离
      for (const auto& nx : g[x]) {
        if (nx == fa) {
          continue;
        }
        dfs(nx, x, dep + 1);
        sz[x] += sz[nx];  // x 的子树大小 += nx 的子树大小
      }
    };

    dfs(0, 0, 0);

    function<void(int, int)> dp = [&](int x, int fa) {
      for (const auto& nx : g[x]) {
        if (nx == fa) {
          continue;
        }
        // ans[x] - sz[nx] + (n - sz[nx])
        //  - sz[nx]: nx 的子树全部缩短 1
        // n - sz[nx]: 其他子树全部增加 1
        ans[nx] = ans[x] + n - 2 * sz[nx];
        dp(nx, x);
      }
    };
    dp(0, 0);
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}