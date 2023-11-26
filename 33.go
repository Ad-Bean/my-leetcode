package main

func search(nums []int, t int) int {
	n := len(nums)
	if n == 1 {
		if nums[0] == t {
			return 0
		}
		return -1
	}

	l, r := 0, n-1
	for l <= r {
		m := l + (r-l)/2
		if nums[m] == t {
			return m
		}

		if nums[m] < nums[n-1] {
			if nums[m] <= t && t <= nums[n-1] {
				l = m + 1
			} else {
				r = m - 1
			}
		} else {
			if nums[0] <= t && t <= nums[m] {
				r = m - 1
			} else {
				l = m + 1
			}
		}
	}
	return -1
}
