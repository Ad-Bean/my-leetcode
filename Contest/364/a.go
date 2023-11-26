package main

func maximumOddBinaryNumber(s string) string {
	one := 0
	for _, c := range s {
		if c == '1' {
			one++
		}
	}

	n := len(s)
	ans := ""
	for i := 0; i < one-1; i++ {
		ans += "1"
	}
	for i := 0; i < n-one; i++ {
		ans += "0"
	}
	return ans + "1"
}
