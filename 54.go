package main

import "fmt"

func spiralOrder(matrix [][]int) []int {
	m, n := len(matrix), len(matrix[0])
	vis := make([][]bool, m)
	for i := range vis {
		vis[i] = make([]bool, n)
	}

	tot := m * n
	order := make([]int, tot)
	r, c := 0, 0
	dirs := [][]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}
	dir := 0
	for i := 0; i < tot; i++ {
		fmt.Printf("%v %v\n", r, c)
		order[i] = matrix[r][c]
		vis[r][c] = true
		nr, nc := r+dirs[dir][0], c+dirs[dir][1]
		if nr < 0 || nr >= m || nc < 0 || nc >= n || vis[nr][nc] {
			dir = (dir + 1) % 4
		}
		r, c = r+dirs[dir][0], c+dirs[dir][1]
	}
	return order
}

func main() {
	matrix := [][]int{
		{1, 2, 3}, {4, 5, 6}, {7, 8, 9},
	}
	ans := spiralOrder(matrix)
	fmt.Printf("%v\n", ans)
}
