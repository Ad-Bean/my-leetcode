package main

import "sort"

func eliminateMaximum(dist []int, speed []int) int {
	n := len(dist)
	est := make([]int, n)
	for i := 0; i < n; i++ {
		est[i] = (dist[i]-1)/speed[i] + 1
	}
	sort.Ints(est)
	for i := 0; i < n; i++ {
		if est[i] <= i {
			return i
		}
	}
	return n
}
