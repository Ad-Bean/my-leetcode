package main

func diagonalSum(mat [][]int) (sum int) {
	n := len(mat)
	for i := 0; i < n; i++ {
		sum += mat[i][i] + mat[i][n-1-i]
	}
	if n&1 == 1 {
		return sum - mat[n/2][n/2]
	}
	return sum
}
