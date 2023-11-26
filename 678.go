package main

import (
	"fmt"
)

func checkValidString(s string) bool {
	l, r := 0, 0
	for _, c := range s {
		if c == '(' {
			l, r = l+1, r+1
		} else if c == ')' {
			l, r = l-1, r-1
		} else {
			l, r = l-1, r+1
		}
		l = max(l, 0)
		if l > r {
			return false
		}
	}
	return l == 0
}

func main() {
	s := "("
	ans := checkValidString(s)
	fmt.Printf("%v\n", ans)
}
