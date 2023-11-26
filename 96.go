package main

// dp[0] = 1
// dp[1] = 1
// dp[2] = dp[0]dp[1] + dp[1]dp[0] = 2
// dp[3] = dp[0]dp[2] + dp[1]dp[1] + dp[2]dp[0] = 5
// dp[i] = left(j-1)*right(i-1) j\in[1,i]
func numTrees(n int) int {
	dp := make([]int, n+1)
	dp[0], dp[1] = 1, 1
	for i := 2; i <= n; i++ {
		for j := 1; j <= i; j++ {
			dp[i] += dp[j-1] * dp[i-j]
		}
	}
	return dp[n]
}
