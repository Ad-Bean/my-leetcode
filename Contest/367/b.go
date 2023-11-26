package main

import "fmt"

/*
  1 0 0 0 1 1 0 0 1
0 1 1 1 1 2 3 3 3 4
l           r

*/

func shortestBeautifulSubstring(s string, k int) (ans string) {
	n := len(s)
	prev := make([]int, n+1)
	r := -1
	for i := 0; i < n; i++ {
		if s[i] == '1' {
			prev[i+1] = prev[i] + 1
		} else {
			prev[i+1] = prev[i]
		}
		if prev[i+1] == k && r == -1 {
			r = i + 1
		}
	}
	if prev[n] < k {
		return ""
	}
	ans = s[:r]
	l := 0
	for r = r; r <= n && l < n; r++ {
		for l < n {
			for s[l] == '0' {
				l++
			}
			if prev[r]-prev[l] == k {
				break
			}
			l++
		}
		fmt.Printf("%d %d %v\n", l, r, s[l:r])
		if len(s[l:r]) < len(ans) {
			ans = s[l:r]
		} else if len(s[l:r]) == len(ans) && s[l:r] <= ans {
			ans = s[l:r]
		}
	}
	return
}
func main() {
	fmt.Printf("%v\n", shortestBeautifulSubstring("1100100101011001001", 7))
}
