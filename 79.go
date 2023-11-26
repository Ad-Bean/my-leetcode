package main

var directions = [][]int{
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1},
}

func exist(board [][]byte, word string) bool {
	m, n := len(board), len(board[0])
	vis := make([][]bool, m)
	for i := range vis {
		vis[i] = make([]bool, n)
	}

	var check func(i, j, k int) bool
	check = func(i, j, k int) bool {
		if board[i][j] != word[k] {
			return false
		}
		if k == len(word)-1 {
			return true
		}

		vis[i][j] = true
		for _, dir := range directions {
			ni, nj := i+dir[0], j+dir[1]
			if 0 <= ni && ni < m && 0 <= nj && nj < n && !vis[ni][nj] {
				if check(ni, nj, k+1) {
					return true
				}
			}
		}
		vis[i][j] = false
		return false
	}

	for i, row := range board {
		for j := range row {
			if check(i, j, 0) {
				return true
			}
		}
	}
	return false
}
