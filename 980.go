package main

func uniquePathsIII(grid [][]int) int {
	dir := [][]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
	m, n := len(grid), len(grid[0])
	cnt, si, sj := 0, 0, 0
	for i, r := range grid {
		for j, c := range r {
			if c == 0 {
				cnt++
			} else if c == 1 {
				cnt++
				si, sj = i, j
			}
		}
	}
	var dfs func(int, int, int) int
	dfs = func(i, j, left int) int {
		if grid[i][j] == 2 {
			if left == 0 {
				return 1
			}
			return 0
		}
		tmp := grid[i][j]
		res := 0
		grid[i][j] = -1
		for _, d := range dir {
			ni, nj := i+d[0], j+d[1]
			if ni >= 0 && ni < m && nj >= 0 && nj < n && (grid[ni][nj] == 0 || grid[ni][nj] == 2) {
				res += dfs(ni, nj, left-1)
			}
		}
		grid[i][j] = tmp
		return res
	}
	return dfs(si, sj, cnt)
}
