package main

func searchMatrix(matrix [][]int, target int) bool {
	m, n := len(matrix), len(matrix[0])
	l, r := 0, m*n-1
	for l <= r {
		mid := l + (r-l)/2
		num := matrix[mid/n][mid%n]
		if num == target {
			return true
		} else if num < target {
			l = mid + 1
		} else if num > target {
			r = mid - 1
		}
	}
	return false
}
