package main

func minCapability(nums []int, k int) int {
	max := func(a, b int) int {
		if a > b {
			return a
		}
		return b
	}
	min := func(a, b int) int {
		if a > b {
			return b
		}
		return a
	}
	l, r := nums[0], nums[0]
	for _, num := range nums {
		l = min(l, num)
		r = max(r, num)
	}
	for l <= r {
		m := l + (r-l)/2
		cnt, vis := 0, false
		for _, num := range nums {
			if num <= m && !vis {
				cnt, vis = cnt+1, true
			} else {
				vis = false
			}
		}
		if cnt >= k {
			r = m - 1
		} else {
			l = m + 1
		}
	}
	return l
}
