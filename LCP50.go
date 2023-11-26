package main

import "sort"

func giveGem(gem []int, operations [][]int) int {
	for _, op := range operations {
		a, b := op[0], op[1]
		gemm := gem[a] / 2
		gem[a] /= 2
		gem[b] += gemm
	}
	sort.Ints(gem)
	return gem[len(gem)-1] - gem[0]
}
