package main

import "strings"

func solveNQueens(n int) (ans [][]string) {
	col := make([]int, n)
	onPath := make([]bool, n)
	diag1, diag2 := make([]bool, n*2-1), make([]bool, n*2-1)
	var dfs func(int)
	dfs = func(r int) {
		if r == n {
			board := make([]string, n)
			for i, c := range col {
				board[i] = strings.Repeat(".", c) + "Q" + strings.Repeat(".", n-1-c)
			}
			ans = append(ans, board)
			return
		}
		for c, on := range onPath {
			rc := r - c + n - 1
			if !on && !diag1[r+c] && !diag2[rc] {
				col[r] = c
				onPath[c], diag1[r+c], diag2[rc] = true, true, true
				dfs(r + 1)
				onPath[c], diag1[r+c], diag2[rc] = false, false, false
			}
		}
	}
	dfs(0)
	return
}
