#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
/* 
Alice 有一棵 n 个节点的树，节点编号为 0 到 n - 1 。
树用一个长度为 n - 1 的二维整数数组 edges 表示，其中 edges[i] = [ai, bi] ，
表示树中节点 ai 和 bi 之间有一条边。

Alice 想要 Bob 找到这棵树的根。她允许 Bob 对这棵树进行若干次 猜测 。每一次猜测，Bob 做如下事情：

选择两个 不相等 的整数 u 和 v ，且树中必须存在边 [u, v] 。
Bob 猜测树中 u 是 v 的 父节点 。
Bob 的猜测用二维整数数组 guesses 表示，其中 guesses[j] = [uj, vj] 表示 Bob 猜 uj 是 vj 的父节点。

Alice 非常懒，她不想逐个回答 Bob 的猜测，只告诉 Bob 这些猜测里面 至少 有 k 个猜测的结果为 true 。

给你二维整数数组 edges ，Bob 的所有猜测和整数 k ，请你返回可能成为树根的 节点数目 。如果没有这样的树，则返回 0。


输入：edges = [[0,1],[1,2],[1,3],[4,2]], guesses = [[1,3],[0,1],[1,0],[2,4]], k = 3
输出：3
解释：
根为节点 0 ，正确的猜测为 [1,3], [0,1], [2,4]
根为节点 1 ，正确的猜测为 [1,3], [1,0], [2,4]
根为节点 2 ，正确的猜测为 [1,3], [1,0], [2,4]
根为节点 3 ，正确的猜测为 [1,0], [2,4]
根为节点 4 ，正确的猜测为 [1,3], [1,0]
节点 0 ，1 或 2 为根时，可以得到 3 个正确的猜测。

暴力：枚举每个节点作为根，然后 DFS 判断是否存在边，时间复杂度 O(n^2)
edges.length == n - 1
2 <= n <= 1e5
1 <= guesses.length <= 1e5
0 <= ai, bi, uj, vj <= n - 1

方法一：换根 DP
dp[i] 表示以 i 为根的子树中，有多少个猜测正确的节点数
初始化时从 0 开始 DFS，由于是树，一旦 next == fa 就跳过。
如果 x, next 在猜测中，则 cnt++
dp[0] = cnt

然后从 dp[0] 开始 DFS，
对当前结点 x，父节点 fa
由于当前边是 fa -> x，所以 dp[x] = dp[fa]
为了换边，原本父节点是 fa 现在父节点是 x
如果 fa -> x 在猜测中，则 dp[x]--
如果 x -> fa 在猜测中，则 dp[x]++

如何哈希 guess
字符串：to_string(u) + "," + to_string(v)
或者数学：u * n + v
或者位运算：u << 20 | v 用 long long
 */

typedef long long ll;

class Solution {
 public:
  int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
    int n = edges.size() + 1;  // m 条边 m + 1 个结点
    vector<vector<int>> g(n);
    for (const auto& e : edges) {
      auto u = e[0], v = e[1];
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }

    vector<int> dp(n);
    unordered_map<string, bool> mp;
    for (const auto& e : guesses) {
      string t = to_string(e[0]) + "," + to_string(e[1]);  // 哈希表记录猜测
      mp[t] = true;
    }

    int cnt = 0;
    function<void(int, int)> init = [&](int x, int fa) {
      for (const auto& nx : g[x]) {
        if (nx == fa) {
          continue;  // 忽略父节点，保证是树
        }
        string t = to_string(x) + "," + to_string(nx);
        if (mp[t]) {  // 当前往下找
          cnt++;
        }
        init(nx, x);
      }
    };

    init(0, 0);
    dp[0] = cnt;
    // 得到 dp[0] 之后，再得到其他节点的 dp
    function<void(int, int)> dfs = [&](int x, int fa) {
      // 当前 x 父节点 fa
      // 原本有 fa -> x，现在反了要取消 dp[x] = dp[fa] - 1
      // 如果有 x -> fa，猜测正确，则 dp[x] = dp[fa] + 1
      dp[x] = dp[fa];
      string prev = to_string(fa) + "," + to_string(x);
      string next = to_string(x) + "," + to_string(fa);
      if (mp[prev]) {
        dp[x]--;
      }
      if (mp[next]) {
        dp[x]++;
      }

      for (const auto& nx : g[x]) {
        if (nx == fa) {
          continue;
        }
        dfs(nx, x);
      }
    };

    dfs(0, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      cout << dp[i] << " ";
      if (dp[i] >= k) {
        ans++;
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}, {4, 2}};
  vector<vector<int>> guesses = {{1, 3}, {0, 1}, {1, 0}, {2, 4}};
  int k = 3;
  cout << test.rootCount(edges, guesses, k) << endl;
  return 0;
}
