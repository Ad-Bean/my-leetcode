package main

func findPaths(m int, n int, maxMove int, startRow int, startColumn int) int {
	dirs := []struct{ x, y int }{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}
	const mod = 1e9 + 7
	ans := 0
	dp := make([][][]int, maxMove+1)
	for i := range dp {
		dp[i] = make([][]int, m)
		for j := range dp[i] {
			dp[i][j] = make([]int, n)
		}
	}
	dp[0][startRow][startColumn] = 1
	for i := 0; i < maxMove; i++ {
		for j := 0; j < m; j++ {
			for k := 0; k < n; k++ {
				cnt := dp[i][j][k]
				if cnt > 0 {
					for _, dir := range dirs {
						nx, ny := j+dir.x, k+dir.y
						if nx >= 0 && nx < m && ny >= 0 && ny < n {
							dp[i+1][nx][ny] = (dp[i+1][nx][ny] + cnt) % mod
						} else {
							ans = (ans + cnt) % mod
						}
					}
				}
			}
		}
	}
	return ans
}
