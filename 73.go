package main

func setZeroes(matrix [][]int) {
	n, m := len(matrix), len(matrix[0])
	colZero := false
	for _, row := range matrix {
		if row[0] == 0 {
			colZero = true
		}
		for j := 1; j < m; j++ {
			if row[j] == 0 {
				row[0] = 0
				matrix[0][j] = 0
			}
		}
	}
	for i := n - 1; i >= 0; i-- {
		for j := 1; j < m; j++ {
			if matrix[i][0] == 0 || matrix[0][j] == 0 {
				matrix[i][j] = 0
			}
		}
		if colZero {
			matrix[i][0] = 0
		}
	}
}
