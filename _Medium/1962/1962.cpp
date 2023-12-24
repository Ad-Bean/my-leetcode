#include <bits/stdc++.h>
using namespace std;
/*
你一个整数数组 piles ，数组 下标从 0 开始 ，其中 piles[i] 表示第 i 堆石子中的石子数量。另给你一个整数 k ，请你执行下述操作 恰好 k 次：

选出任一石子堆 piles[i] ，并从中 移除 floor(piles[i] / 2) 颗石子。
注意：你可以对 同一堆 石子多次执行此操作。

返回执行 k 次操作后，剩下石子的 最小 总数。

floor(x) 为 小于 或 等于 x 的 最大 整数。（即，对 x 向下取整）。

输入：piles = [5,4,9], k = 2
输出：12
解释：可能的执行情景如下：
- 对第 2 堆石子执行移除操作，石子分布情况变成 [5,4,5] 。
- 对第 0 堆石子执行移除操作，石子分布情况变成 [3,4,5] 。
剩下石子的总数为 12 。
 
方法一：堆
每次取最大，贪心

*/
typedef long long ll;
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q;
        for (int pile: piles) {
            q.emplace(pile);
        }
        int sum = accumulate(piles.begin(), piles.end(), 0);
        while(k--) {
            int t = q.top();
            q.pop();
            sum -= t/2;
            if (t - t/2>0) {
                q.emplace(t - t/2);
            }
        }
        return sum;
    }
};
int main() {

  Solution test;
  return 0;
}