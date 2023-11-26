package main

import "fmt"

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func minChanges(s string) (cnt int) {
	n := len(s)

	mp := map[byte]int{}
	for i := 0; i < n; i++ {
		mp[s[i]]++
		if i > 0 && (i+1)%2 == 0 {
			if mp['0'] != 0 && mp['1'] != 0 {
				a, b := mp['0'], mp['1']
				cnt += 2 - max(a, b)
			}
			mp['0'] = 0
			mp['1'] = 0
		}
	}
	return
}

func main() {
	s := "1001111111111111011111"
	fmt.Printf("%v\n", minChanges(s))
}
