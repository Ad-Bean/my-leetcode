package main

func numIslands(grid [][]byte) (ans int) {
	m, n := len(grid), len(grid[0])
	var dfs func(int, int)
	dfs = func(x, y int) {
		if x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != '1' {
			return
		}
		grid[x][y] = '0'
		dfs(x-1, y)
		dfs(x+1, y)
		dfs(x, y-1)
		dfs(x, y+1)
	}

	for i := range grid {
		for j := range grid[i] {
			if grid[i][j] == '1' {
				ans++
				dfs(i, j)
			}
		}
	}
	return
}
