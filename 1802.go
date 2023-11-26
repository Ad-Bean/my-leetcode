package main

import "sort"

func f(big, length int) int {
	if length == 0 {
		return 0
	}
	if length <= big {
		return (2*big + 1 - length) * length / 2
	}
	return (big+1)*big/2 + length - big
}

func maxValue(n, index, maxSum int) int {
	return sort.Search(maxSum, func(mid int) bool {
		left := index
		right := n - index - 1
		return mid+f(mid, left)+f(mid, right) >= maxSum
	})
}
