package main

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
func romanToInt(s string) int {
	mp := map[byte]int{
		'I': 1,
		'V': 5,
		'X': 10,
		'L': 50,
		'C': 100,
		'D': 500,
		'M': 1000,
	}
	val := 0
	for i := range s {
		if i+1 < len(s) && mp[s[i]] < mp[s[i+1]] {
			val -= mp[s[i]]
		} else {
			val += mp[s[i]]
		}
	}
	return val
}
