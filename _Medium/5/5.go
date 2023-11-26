package main

func dp(s string, l, r int) (int, int) {
	for l >= 0 && r < len(s) {
		if s[l] == s[r] {
			l--
			r++
		} else {
			break
		}
	}
	return l + 1, r - 1
}

func longestPalindrome(s string) string {
	st, ed, n := 0, 0, len(s)
	for i := 0; i < n; i++ {
		l1, r1 := dp(s, i, i)
		l2, r2 := dp(s, i, i+1)
		if r1-l1 > ed-st {
			st, ed = l1, r1
		}
		if r2-l2 > ed-st {
			st, ed = l2, r2
		}
	}
	return s[st : ed+1]
}
