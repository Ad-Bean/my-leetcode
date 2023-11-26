package main

/*
输入：n = 1, k = 6, target = 3
输出：1
解释：你扔一个有 6 个面的骰子。
得到 3 的和只有一种方法。


输入：n = 2, k = 6, target = 7
输出：6
解释：你扔两个骰子，每个骰子有 6 个面。
得到 7 的和有 6 种方法：1+6 2+5 3+4 4+3 5+2 6+1。

一个骰子，扔到 1，问题分解：一个骰子扔到之和为 6

dp[i][j] 表示 i 个骰子扔到和为 j 的方法数量
dp[i][j] = dp[i-1][j-1] + dp[i-1][j-2] ... + dp[i-1][j-k]

j - k >= 0
*/
func numRollsToTarget(n int, k int, target int) int {
	if n*k < target {
		return 0
	}
	const mod = 1e9 + 7
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, target+1)
	}
	dp[0][0] = 1
	for i := 1; i <= n; i++ {
		for j := 0; j <= target; j++ {
			for d := 1; d <= j && d <= k; d++ {
				dp[i][j] = (dp[i][j] + dp[i-1][j-d]) % mod
			}
		}
	}
	return dp[n][target]
}
