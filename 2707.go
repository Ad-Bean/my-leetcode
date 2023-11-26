package main

/*
dp[i] 表示 s 前 i 个字符的子问题
dp[i] = dp[i - 1] + 1

*/
func minExtraChar(s string, dictionary []string) int {
	mp := map[string]bool{}
	for _, s := range dictionary {
		mp[s] = true
	}
	n := len(s)
	f := make([]int, n+1)
	for i := 0; i < n; i++ {
		f[i+1] = f[i] + 1
		for j := 0; j <= i; j++ {
			if mp[s[j:i+1]] {
				f[i+1] = min(f[i+1], f[j])
			}
		}
	}
	return f[n]
}
