package main

import "fmt"

// why dp, cur step is not the optimal choice, and it impacts next steps
// dp[i]: s[:i-1] -> s[:j-1] + s[j:i-1] both validate
// since dp[:i] validates, s[:j-1] equals dp[j]
// only check whether s[j:i-1] is in the word dictionary
// dp[i] = dp[j] && check(s[j:i-1])
func wordBreak(s string, wordDict []string) bool {
	mp := map[string]bool{}
	for _, w := range wordDict {
		mp[w] = true
	}
	n := len(s)
	dp := make([]bool, n+1)
	dp[0] = true
	for i := 1; i <= n; i++ {
		// fmt.Printf("%d %v \n", i, dp[i])
		for j := 0; j < i; j++ {
			fmt.Printf("%d %v %s\n", j, dp[j], s[j:i])
			if dp[j] && mp[s[j:i]] {
				dp[i] = true
				break // ?
			}
		}
	}

	return dp[n]
}

func main() {
	s := "applepenapple"
	wordDict := []string{"apple", "pen"}
	res := wordBreak(s, wordDict)
	fmt.Printf("\n\n%v\n\n", res)
}
