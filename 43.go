package main

import "strconv"

func multiply(num1 string, num2 string) string {
	if num1 == "0" || num2 == "0" {
		return "0"
	}

	m, n := len(num1), len(num2)
	ans := make([]int, m+n)
	for i := m - 1; i >= 0; i-- {
		x := int(num1[i] - '0')
		for j := n - 1; j >= 0; j-- {
			y := int(num2[j] - '0')
			ans[i+j+1] += x * y
		}
	}
	for i := m + n - 1; i > 0; i-- {
		ans[i-1] += ans[i] / 10
		ans[i] %= 10
	}
	ret := ""
	idx := 0
	if ans[0] == 0 {
		idx = 1
	}
	for ; idx < m+n; idx++ {
		ret += strconv.Itoa(ans[idx])
	}
	return ret
}
