package main

import (
	"fmt"
	"math"
	"sort"
)

func check(piles []int, k, h int) bool {
	ans := 0
	if k == 0 {
		return false
	}
	for _, p := range piles {
		ans += int(math.Ceil(float64(p) / float64(k)))
	}
	return ans <= h
}

func minEatingSpeed(piles []int, h int) int {
	return sort.Search(1e9, func(m int) bool {
		return check(piles, m, h)
	})
}

func main() {
	piles := []int{3, 6, 7, 11}
	h := 8
	res := minEatingSpeed(piles, h)
	fmt.Printf("\n%d\n", res)
}
