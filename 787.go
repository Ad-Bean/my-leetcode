package main

func findCheapestPrice(n int, flights [][]int, src int, dst int, k int) int {
	dp := make([][]int, k+2)
	for i := range dp {
		dp[i] = make([]int, n)
		for j := range dp[i] {
			dp[i][j] = 0x3f3f3f3f
		}
	}
	dp[0][src] = 0
	for t := 1; t <= k+1; t++ {
		for _, flight := range flights {
			j, i, cost := flight[0], flight[1], flight[2]
			dp[t][i] = min(dp[t][i], dp[t-1][j]+cost)
		}
	}
	ans := 0x3f3f3f3f
	for t := 1; t <= k+1; t++ {
		ans = min(ans, dp[t][dst])
	}
	if ans == 0x3f3f3f3f {
		return -1
	}
	return ans
}
