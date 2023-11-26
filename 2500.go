package main

import (
	"sort"
)

func deleteGreatestValue(grid [][]int) (res int) {
	m, n := len(grid), len(grid[0])
	for i := 0; i < m; i++ {
		sort.Ints(grid[i])
	}

	for j := 0; j < n; j++ {
		mx := 0
		for i := 0; i < m; i++ {
			mx = max(mx, grid[i][j])
		}
		res += mx
	}
	return
}
