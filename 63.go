package main

func uniquePathsWithObstacles(grid [][]int) int {
	n, m := len(grid), len(grid[0])
	f := make([]int, m)
	if grid[0][0] == 0 {
		f[0] = 1
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if grid[i][j] == 1 {
				f[j] = 0
				continue
			}
			if j-1 >= 0 && grid[i][j-1] == 0 {
				f[j] += f[j-1]
			}
		}
	}
	return f[m-1]
}
