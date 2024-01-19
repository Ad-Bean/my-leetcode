package main

import "fmt"

var symbols = map[rune]int{
	'I': 1,
	'V': 5,
	'X': 10,
	'L': 50,
	'C': 100,
	'D': 500,
	'M': 1000,
}

func romanToInt(s string) int {
	n := len(s)
	ans := 0
	for i := range s {
		val := symbols[rune(s[i])]
		if i < n-1 && val < symbols[rune(s[i+1])] {
			ans -= val
		} else {
			ans += val
		}
	}
	return ans
}

func main() {
	s := "VVVVVVVVVVVVVVVVV"
	ans := romanToInt(s)
	fmt.Printf("\n\n%d\n\n", ans)
}
