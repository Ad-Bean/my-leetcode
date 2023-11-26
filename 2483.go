package main

import "strings"

func bestClosingTime(customers string) (ans int) {
	cost := strings.Count(customers, "Y")
	minCost := cost
	for i, c := range customers {
		if c == 'N' {
			cost++
		} else {
			cost--
			if cost < minCost {
				cost = minCost
				ans = i + 1
			}
		}
	}
	return
}
