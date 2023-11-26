package main

// 01 knapsack dp
// free cnt + pay cnt == n
// free cnt <= pay time
// pay time + pay cnt >= n
// dp[i][j] = min(dp[i-1][j-time[i]-1]+cost[i], dp[i-1][j])
func paintWalls(cost []int, time []int) int {
	n := len(cost)
	dp := make([]int, n+1)
	for i := 1; i <= n; i++ {
		dp[i] = 0x3f3f3f3f
	}
	for i := range cost {
		for j := n; j > 0; j-- {
			dp[j] = min(dp[j], dp[max(j-(time[i]+1), 0)]+cost[i])
		}
	}
	return dp[n]
}
