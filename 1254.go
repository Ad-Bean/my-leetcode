package main

func closedIsland(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	var dfs func(int, int)
	dfs = func(x, y int) {
		if x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 1 {
			return
		}
		grid[x][y] = 1
		dfs(x-1, y)
		dfs(x, y-1)
		dfs(x+1, y)
		dfs(x, y+1)
	}
	for i := 0; i < m; i++ {
		dfs(i, 0)
		dfs(i, n-1)
	}
	for j := 1; j < n-1; j++ {
		dfs(0, j)
		dfs(m-1, j)
	}

	ans := 0
	for i := 1; i < m-1; i++ {
		for j := 1; j < n-1; j++ {
			if grid[i][j] == 0 {
				dfs(i, j)
				ans++
			}
		}
	}
	return ans
}
