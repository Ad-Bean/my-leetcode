package main

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

// C(n, 2)
func numPairsDivisibleBy60(time []int) int {
	cnt := make([]int, 60) // residual
	for _, t := range time {
		cnt[t%60]++
	}
	var res int
	for i := 1; i < 30; i++ {
		res += cnt[i] * cnt[60-i]
	}
	res += cnt[0]*(cnt[0]-1)/2 + cnt[30]*(cnt[30]-1)/2
	return res
}
