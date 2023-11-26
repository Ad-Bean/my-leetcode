package main

import (
	"fmt"
)

func removeDuplicates(s string, k int) string {
	n := 0
	for n != len(s) {
		n = len(s)
		for i, cnt := 0, 1; i < len(s); i++ {
			if i == 0 || s[i] != s[i-1] {
				cnt = 1
			} else if s[i] == s[i-1] {
				cnt += 1
				if cnt == k {
					s = s[:i-k+1] + s[i+1:]
					break
				}
			}
		}
	}
	return s
}

func main() {
	s := "deeedbbcccbdaa"
	k := 3
	tmp := removeDuplicates(s, k)
	fmt.Printf("%s\n", tmp)
}
