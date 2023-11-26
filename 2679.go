package main

import "sort"

func matrixSum(nums [][]int) int {
	res := 0
	m, n := len(nums), len(nums[0])
	for i := 0; i < m; i++ {
		sort.Ints(nums[i])
	}

	for j := 0; j < n; j++ {
		maxV := 0
		for i := 0; i < m; i++ {
			if nums[i][j] > maxV {
				maxV = nums[i][j]
			}
		}
		res += maxV
	}
	return res
}
