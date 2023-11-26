package main

import (
	"sort"
)

func isNStraightHand(hand []int, groupSize int) bool {
	n := len(hand)
	if n%groupSize != 0 {
		return false
	}

	sort.Ints(hand)
	cnt := map[int]int{}
	for _, num := range hand {
		cnt[num]++
	}
	for _, num := range hand {
		if cnt[num] == 0 {
			continue
		}

		for i := 0; i < groupSize; i++ {
			if cnt[num+i] == 0 {
				return false
			}
			cnt[num+i]--
		}
	}
	return true
}
