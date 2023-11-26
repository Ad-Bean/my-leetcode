package main

import (
	"sort"
)

func matchPlayersAndTrainers(players []int, trainers []int) int {
	sort.Ints(players)
	sort.Ints(trainers)
	j := 0
	n, m := len(players), len(trainers)
	for i, p := range players {
		for j < m && p > trainers[j] {
			j++
		}
		if j == m {
			return i
		}
		j++
	}
	return n
}
