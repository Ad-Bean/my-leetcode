package main

import "fmt"

func numSmallerByFrequency(queries []string, words []string) []int {
	var f func(string) int
	f = func(s string) int {
		cnt := 0
		ch := 'z'
		for _, c := range s {
			if c < ch {
				ch = c
				cnt = 1
			} else if c == ch {
				cnt++
			}
		}
		return cnt
	}

	count := make([]int, 26)
	for _, s := range words {
		count[f(s)] += 1
	}
	fmt.Println(count)
	for i := 9; i >= 1; i-- {
		count[i] += count[i+1]
	}
	res := make([]int, len(queries))
	for i, s := range queries {
		res[i] = count[f(s)+1]
	}
	return res
}

func main() {
	queries := []string{"cbd"}
	words := []string{"zaaaz"}
	res := numSmallerByFrequency(queries, words)
	fmt.Println(res)
}
