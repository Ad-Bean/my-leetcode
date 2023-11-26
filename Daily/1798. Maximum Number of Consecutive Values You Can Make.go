package main

import "sort"

func getMaximumConsecutive(coins []int) int {
	res := 1
	sort.Ints(coins)
	for _, c := range coins {
		if c > res {
			break
		}
		res += c
	}
	return res
}
