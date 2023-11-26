package main

func uniquePaths(m int, n int) int {
	// dp := make([][]int, m)
	// for i := range dp {
	// 	dp[i] = make([]int, n)
	// }
	// for i := range dp {
	// 	for j := range dp[i] {
	// 		if i == 0 && j > 0 {
	// 			dp[i][j] = 1
	// 		} else if j == 0 && i > 0 {
	// 			dp[i][j] = 1
	// 		} else if i > 0 && j > 0 {
	// 			dp[i][j] = dp[i-1][j] + dp[i][j-1]
	// 		}
	// 	}
	// }
	// return dp[m-1][n-1]
	dp := make([]int, n)
	for i := range dp {
		dp[i] = 1
	}
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			dp[j] += dp[j-1]
		}
	}
	return dp[n-1]
}

//
// 3,2
// 0 1
// 1 2
// 2 4
