package main

import "sort"

func kWeakestRows(mat [][]int, k int) (ans []int) {
	m := len(mat)
	powers := make([][]int, m)
	for i := range powers {
		powers[i] = make([]int, 2)
	}

	for i, row := range mat {
		sum := 0
		for _, c := range row {
			sum += c
		}
		powers[i][0], powers[i][1] = i, sum
	}
	sort.Slice(powers, func(i, j int) bool {
		if powers[i][1] == powers[j][1] {
			return powers[i][0] < powers[j][0]
		} else {
			return powers[i][1] < powers[j][1]
		}
	})
	for _, power := range powers[:k] {
		ans = append(ans, power[0])
	}
	return
}
