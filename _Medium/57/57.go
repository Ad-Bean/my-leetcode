package main

func insert(intervals [][]int, ni []int) (ans [][]int) {
	l, r := ni[0], ni[1]
	merged := false
	for _, itv := range intervals {
		ll, rr := itv[0], itv[1]
		if r < ll {
			if !merged {
				ans = append(ans, []int{l, r})
				merged = true
			}
			ans = append(ans, itv)
		} else if l > rr {
			ans = append(ans, itv)
		} else {
			l, r = min(l, ll), max(r, rr)
		}
	}

	if !merged {
		ans = append(ans, []int{l, r})
	}
	return
}
