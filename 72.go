package main

/*
dp[i][j] = min(dp[i-1][j]+1,

	           dp[i][j-1]+1,
			   dp[i-1][j-1]+int(word1[i]!=word2[j]))
*/
func minDistance(word1 string, word2 string) int {
	len1, len2 := len(word1), len(word2)
	dp := make([][]int, len1+1)
	for i := range dp {
		dp[i] = make([]int, len2+1)
	}
	for i := 1; i <= len2; i++ {
		dp[0][i] = i
	}
	for i, c1 := range word1 {
		dp[i+1][0] = i + 1
		for j, c2 := range word2 {
			if c1 == c2 {
				dp[i+1][j+1] = dp[i][j]
			} else {
				dp[i+1][j+1] = min(min(dp[i][j+1], dp[i+1][j]), dp[i][j]) + 1
			}
		}
	}
	return dp[len1][len2]
}
