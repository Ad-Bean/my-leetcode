package main

import (
	"math"
)

// f[i][j] = max(f[i-1][j], f[i-1][(j+x)%3] + x)
func maxSumDivThree(nums []int) int {
	n := len(nums)
	f := make([][3]int, n+1)
	f[0][1] = math.MinInt
	f[0][2] = math.MinInt
	for i, x := range nums {
		for j := 0; j < 3; j++ {
			f[i+1][j] = max(f[i][j], f[i][(j+x)%3]+x)
		}
	}
	return f[n][0]
}
