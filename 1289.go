package main

func minFallingPathSum(grid [][]int) int {
	n := len(grid)
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, n)
		for j := range dp[i] {
			dp[i][j] = 0x3f3f3f3f
		}
	}
	for i := range dp {
		dp[0][i] = grid[0][i]
	}
	for i := 1; i < n; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				if j == k {
					continue
				}
				dp[i][j] = min(dp[i][j], dp[i-1][k]+grid[i][j])
			}
		}
	}
	res := 0x3f3f3f3f
	for i := 0; i < n; i++ {
		res = min(res, dp[n-1][i])
	}
	return res
}
