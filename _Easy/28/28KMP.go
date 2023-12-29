package main

func strStr(haystack string, needle string) int {
	n, m := len(haystack), len(needle)
	haystack, needle = " "+haystack, " "+needle
	next := make([]int, m+1)
	for i, j := 2, 0; i <= m; i++ {
		for j > 0 && needle[i] != needle[j+1] {
			j = next[j]
		}
		if needle[i] == needle[j+1] {
			j++
		}
		next[i] = j
	}
	for i, j := 1, 0; i <= n; i++ {
		for j > 0 && haystack[i] != needle[j+1] {
			j = next[j]
		}
		if haystack[i] == needle[j+1] {
			j++
		}
		if j == m {
			return i - m
		}
	}
	return -1
}
