package main

// O(nm) -> O(nlogm) -> O(n + m)
// sort.SearchInts(row, target) 内置二分
func findNumberIn2DArray(matrix [][]int, target int) bool {
	for _, row := range matrix {
		l, r := 0, len(row)-1
		for l <= r {
			m := l + (r-l)/2
			if row[m] == target {
				return true
			}
			if row[m] < target {
				l = m + 1
			} else {
				r = m - 1
			}
		}
	}
	return false
}

func findNumberIn2DArrayOpt(matrix [][]int, target int) bool {
	if len(matrix) == 0 {
		return false
	}
	m, n := len(matrix), len(matrix[0])
	x, y := 0, n-1
	// starts from right top
	for x < m && y >= 0 {
		if matrix[x][y] == target {
			return true
		}

		if matrix[x][y] > target {
			y--
		} else {
			x++
		}
	}
	return false
}
