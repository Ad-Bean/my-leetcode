package main

func isValidSudoku(board [][]byte) bool {
	r, c, b := [9][9]int{}, [9][9]int{}, [3][3][9]int{}
	for i, row := range board {
		for j, col := range row {
			if col == '.' {
				continue
			}
			num := col - '1'
			r[i][num]++
			c[i][num]++
			b[i/3][j/3][num]++
			if r[i][num] > 1 || c[i][num] > 1 || b[i/3][j/3][num] > 1 {
				return false
			}
		}
	}
	return true
}
