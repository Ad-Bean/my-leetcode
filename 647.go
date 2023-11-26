package main

// dp[i][j] = s[i] == s[j] && (dp[i+1][j-1])
func countSubstrings1(s string) int {
	ans, n := 0, len(s)

	dp := make([][]bool, n)
	for i := range dp {
		dp[i] = make([]bool, n)
	}

	for j := 0; j < n; j++ {
		for i := 0; i <= j; i++ {
			if s[i] == s[j] && (j-i < 2 || dp[i+1][j-1]) {
				dp[i][j] = true
				ans++
			}
		}
	}
	return ans
}

// abba
// center: 0,1,2,3, 01,12,23
func countSubstrings(s string) (ans int) {
	n := len(s)
	for i := 0; i < 2*n-1; i++ {
		l := i / 2
		r := l + i%2
		for l >= 0 && r < n && s[l] == s[r] {
			ans++
			l--
			r++
		}
	}
	return
}
