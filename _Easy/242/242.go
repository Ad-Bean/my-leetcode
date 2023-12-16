package main

import (
	"sort"
)

func isAnagram(s string, t string) bool {
	s1, t1 := []byte(s), []byte(t)
	sort.Slice(s1, func(i, j int) bool { return s1[i] < s1[j] })
	sort.Slice(t1, func(i, j int) bool { return t1[i] < t1[j] })
	return string(s1) == string(t1)
}
