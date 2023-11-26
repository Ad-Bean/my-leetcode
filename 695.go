package main

import "fmt"

func maxAreaOfIsland1(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	dir := [][]int{{0, 1}, {0, -1}, {-1, 0}, {1, 0}}
	var dfs func(int, int) int
	dfs = func(x int, y int) int {
		if x < 0 || y < 0 || x == m || y == n || grid[x][y] == 0 {
			return 0
		}
		ans := 1
		grid[x][y] = 0
		for i := range dir {
			nx, ny := x+dir[i][0], y+dir[i][1]
			ans += dfs(nx, ny)
		}
		return ans
	}

	maxArea := 0
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			maxArea = max(maxArea, dfs(i, j))
		}
	}
	return maxArea
}
func maxAreaOfIsland(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	dir := [][]int{{0, 1}, {0, -1}, {-1, 0}, {1, 0}}
	var dfs func(int, int) int
	dfs = func(x int, y int) int {
		if x < 0 || y < 0 || x == m || y == n || grid[x][y] == 0 {
			return 0
		}
		ans := 1
		grid[x][y] = 0
		for i := range dir {
			nx, ny := x+dir[i][0], y+dir[i][1]
			ans += dfs(nx, ny)
		}
		return ans
	}

	maxArea := 0
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			maxArea = max(maxArea, dfs(i, j))
		}
	}
	return maxArea
}

func main() {
	grid := [][]int{
		{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
	}
	ans := maxAreaOfIsland(grid)
	fmt.Printf("%d\n", ans)
}
