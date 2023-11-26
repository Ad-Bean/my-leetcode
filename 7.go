package main

import (
	"math"
)

func reverse(x int) (ans int) {
	for x != 0 {
		num := x % 10
		ans = ans*10 + num
		if ans > math.MaxInt32 || ans < math.MinInt32 {
			return 0
		}
		x /= 10
	}
	return
}
