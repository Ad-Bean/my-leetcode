package main

import (
	"sort"
)

func pondSizes(land [][]int) []int {
	m, n := len(land), len(land[0])
	var dfs func(int, int) int
	dfs = func(x, y int) int {
		if x < 0 || x >= m || y < 0 || y >= n || land[x][y] != 0 {
			return 0
		}
		land[x][y] = 1
		cnt := 1
		for i := x - 1; i <= x+1; i++ {
			for j := y - 1; j <= y+1; j++ {
				cnt += dfs(i, j)
			}
		}
		return cnt
	}
	var ans []int
	for i, row := range land {
		for j, col := range row {
			if col == 0 {
				ans = append(ans, dfs(i, j))
			}
		}
	}
	sort.Ints(ans)
	return ans
}
