package main

import (
	"unicode"
)

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func camelMatch(queries []string, pattern string) []bool {
	n := len(queries)
	res := make([]bool, n)
	for i := 0; i < n; i++ {
		res[i] = true
		j := 0
		for _, c := range queries[i] {
			if j < len(pattern) && byte(c) == pattern[j] {
				j++
			} else if unicode.IsUpper(c) {
				res[i] = false
				break
			}
		}
		if j < len(pattern) {
			res[i] = false
		}
	}
	return res
}
