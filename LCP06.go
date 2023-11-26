package main

func minCount(coins []int) (ans int) {
	for _, coin := range coins {
		ans += (coin + 1) / 2
	}
	return
}
