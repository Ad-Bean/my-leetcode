package main

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// greedy
func minTaps(n int, ranges []int) int {
	right := make([]int, n+1)
	for i := range ranges {
		right[i] = i
	}
	for i, r := range ranges {
		ll := max(0, i-r)
		rr := min(n, i+r)
		right[ll] = max(right[ll], rr)
	}

	last, ret, pre := 0, 0, 0
	for i := 0; i < n; i++ {
		last = max(last, right[i])
		if i == last {
			return -1
		}
		if i == pre {
			ret++
			pre = last
		}
	}
	return ret
}
