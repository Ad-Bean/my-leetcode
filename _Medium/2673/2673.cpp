#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个整数 n 表示一棵 满二叉树 里面节点的数目，节点编号从 1 到 n 。
根节点编号为 1 ，树中每个非叶子节点 i 都有两个孩子，分别是左孩子 2 * i 和右孩子 2 * i + 1 。

树中每个节点都有一个值，用下标从 0 开始、长度为 n 的整数数组 cost 表示，其中 cost[i] 是第 i + 1 个节点的值。
每次操作，你可以将树中 任意 节点的值 增加 1 。你可以执行操作 任意 次。

你的目标是让根到每一个 叶子结点 的路径值相等。请你返回 最少 需要执行增加操作多少次。

3 <= n <= 10^5

满二叉树 指的是一棵树，它满足树中除了叶子节点外每个节点都恰好有 2 个子节点，且所有叶子节点距离根节点距离相同。
路径值 指的是路径上所有节点的值之和。

方法一：贪心 + 满二叉树自底向上
从倒数第二层开始 i = n/2-1，对其孩子 2*i 和 2*i+1，使其值相等 取 abs(cost[2*i] - cost[2*i+1])，也就是变成最大的那个子节点
此时根到该节点的路径值就是 root + cost[i - 1] + max(cost[2*i], cost[2*i+1])


 */
class Solution {
 public:
  int minIncrements(int n, vector<int>& cost) {
    int ans = 0;
    for (int i = n / 2; i >= 1; i--) {
      int l = 2 * i, r = 2 * i + 1;
      ans += abs(cost[l - 1] - cost[r - 1]);
      cost[i - 1] += max(cost[l - 1], cost[r - 1]);
    }
    return ans;
  }
};

int main() {

  Solution test;
  int n = 7;
  vector<int> cost = {1, 5, 2, 2, 3, 3, 1};
  cout << test.minIncrements(n, cost) << endl;
  return 0;
}
