package main

// n, m := len(s), len(t)
// i, j := 0, 0
// for i < n && j < m {
// 	if s[i] == t[j] {
// 		i++
// 	}
// 	j++
// }
// return i == n
func isSubsequence(s string, t string) bool {
	// dp[i][j]
	// if t[i] == j, then dp[i][j] = i
	//
	n, m := len(s), len(t)
	dp := make([][26]int, m+1)
	for i := 0; i < 26; i++ {
		dp[m][i] = m
	}
	for i := m - 1; i >= 0; i-- {
		for j := 0; j < 26; j++ {
			if t[i] == byte(j+'a') {
				dp[i][j] = i
			} else {
				dp[i][j] = dp[i+1][j]
			}
		}
	}
	add := 0
	for i := 0; i < n; i++ {
		if dp[add][int(s[i]-'a')] == m {
			return false
		}
		add = dp[add][int(s[i]-'a')] + 1
	}
	return true
}
