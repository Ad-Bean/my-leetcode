package main

// dp[i][j] = matrix[i][j] + min(dp[i-1,j], dp[i-1, j-1], dp[i-1, j+1])
func minFallingPathSum(m [][]int) int {
	n := len(m)
	for i := 1; i < n; i++ {
		m[i][0] += min(m[i-1][0], m[i-1][1])
		m[i][n-1] += min(m[i-1][n-1], m[i-1][n-2])
		for j := 1; j < n-1; j++ {
			m[i][j] += min(m[i-1][j], min(m[i-1][j-1], m[i-1][j+1]))
		}
	}
	ans := 0x3f3f3f3f
	for _, num := range m[n-1] {
		ans = min(ans, num)
	}
	return ans
}
