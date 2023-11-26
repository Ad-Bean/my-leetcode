package main

func isPalindrome(s string) bool {
	tmp := ""
	for _, c := range s {
		if 'a' <= c && c <= 'z' {
			tmp += string(c)
		} else if 'A' <= c && c <= 'Z' {
			tmp += string((c - 'A') + 'a')
		} else if '0' <= c && c <= '9' {
			tmp += string(c)
		}
	}
	l, r := 0, len(tmp)-1
	for l < r {
		if tmp[l] != tmp[r] {
			return false
		}
		l, r = l+1, r-1
	}
	return true
}
