package main

/*
dp[i] means s[1...i] can decode how many nums
s = "06"
dp[0] = 1
dp[1] = 0
s = "1126"
dp[0] = 1
dp[1] = 1
dp[2] = 2
dp[3] = 3
*/
func numDecodings(s string) int {
	n := len(s)
	dp := make([]int, n+1)
	dp[0] = 1
	for i := 1; i <= n; i++ {
		if s[i-1] != '0' {
			dp[i] += dp[i-1]
		}
		if i >= 2 && s[i-2] != '0' {
			num := (s[i-2]-'0')*10 + (s[i-1] - '0')
			if num <= 26 {
				dp[i] += dp[i-2]
			}
		}
	}
	return dp[n]
}
