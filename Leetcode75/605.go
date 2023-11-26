package main

import (
	"fmt"
)

func canPlaceFlowers(flowerbed []int, n int) bool {
	count := 0
	m := len(flowerbed)
	prev := -1
	for i := 0; i < m; i++ {
		if flowerbed[i] == 1 {
			if prev < 0 {
				count += i / 2
			} else {
				count += (i - prev - 2) / 2
			}
			if count >= n {
				return true
			}
			prev = i
		}
	}
	if prev < 0 {
		count += (m + 1) / 2
	} else {
		count += (m - prev - 1) / 2
	}
	return count >= n
}

func main() {
	// flowerbed := []int{1, 0, 0, 0, 1, 0, 0}
	// n := 2
	flowerbed := []int{0}
	n := 1
	res := canPlaceFlowers(flowerbed, n)
	fmt.Printf("%v\n", res)
}
