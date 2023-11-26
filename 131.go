package main

func isPalindrome(s string, l, r int) bool {
	for l < r {
		if s[l] != s[r] {
			return false
		}
		l++
		r--
	}
	return true
}

func partition(s string) [][]string {
	n := len(s)
	path := []string{}
	ans := [][]string{}
	var dfs func(int, int)
	dfs = func(i, st int) {
		if i == n {
			ans = append(ans, append([]string{}, path...))
			return
		}

		if i < n-1 {
			dfs(i+1, st)
		}

		if isPalindrome(s, st, i) {
			path = append(path, s[st:i+1])
			dfs(i+1, i+1)
			path = path[:len(path)-1]
		}
	}
	dfs(0, 0)
	return ans
}
