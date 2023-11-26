package main

import (
	"fmt"
)

func solve(board [][]byte) {
	m, n := len(board), len(board[0])
	var dfs func(int, int)
	dfs = func(x, y int) {
		if x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O' {
			return
		}
		board[x][y] = 'A'
		dfs(x-1, y)
		dfs(x+1, y)
		dfs(x, y+1)
		dfs(x, y-1)
	}

	for i := 0; i < m; i++ {
		dfs(i, 0)
		dfs(i, n-1)
	}
	for i := 1; i < n-1; i++ {
		dfs(0, i)
		dfs(m-1, i)
	}
	for i := range board {
		for j := range board[i] {
			if board[i][j] == 'A' {
				board[i][j] = 'O'
			} else if board[i][j] == 'O' {
				board[i][j] = 'X'
			}
		}
	}
	return
}

func main() {
	board := [][]byte{
		{'X', 'X', 'X', 'X'},
		{'X', 'O', 'O', 'X'},
		{'X', 'X', 'O', 'X'},
		{'X', 'O', 'X', 'X'},
	}
	solve(board)
	fmt.Printf("%s\n", board)
}
