package main

func longestSemiRepetitiveSubstring(s string) int {
	ans, l, r := 1, 0, 1
	flag := 0
	n := len(s)
	for r < n {
		if s[r] == s[r-1] {
			flag++
			if flag > 1 {
				l++
				for s[l] != s[l-1] {
					l++
				}
				flag = 1
			}
		}
		ans = max(ans, r-l+1)
		r++
	}
	return ans
}
