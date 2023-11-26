package main

import (
	"fmt"
	"sort"
)

func closeStrings(word1, word2 string) bool {
	c1, c2 := make([]int, 26), make([]int, 26)
	for _, ch := range word1 {
		c1[ch-'a']++
	}
	for _, ch := range word2 {
		c2[ch-'a']++
	}
	for i := 0; i < 26; i++ {
		// 都没出现
		if c1[i]+c2[i] == 0 {
			continue
		}
		// 一个出现一个没出现
		if c1[i] == 0 || c2[i] == 0 {
			return false
		}
	}
	// 所有频次相同
	sort.Ints(c1)
	sort.Ints(c2)
	for i := 0; i < 26; i++ {
		if c1[i] != c2[i] {
			return false
		}
	}
	return true
}
func main() {
	word1 := "xyzabcd"
	word2 := "zzzzzzzzzzzaaaaaaaaaa"
	ans := closeStrings(word1, word2)

	fmt.Printf("%v\n", ans)
}
