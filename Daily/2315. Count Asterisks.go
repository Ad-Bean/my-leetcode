package main

func countAsterisks(s string) int {
	res := 0
	flag := true
	for _, v := range s {
		if v == '|' {
			flag = !flag
		} else if v == '*' && flag {
			res++
		}
	}
	return res
}
