package main

/* binary search */
func findDuplicate(nums []int) (ans int) {
	n := len(nums)
	l, r := 1, n-1
	for l <= r {
		m := l + (r-l)/2
		cnt := 0
		for i := 0; i < n; i++ {
			if nums[i] <= m {
				cnt++
			}
		}
		if cnt <= m {
			l = m + 1
		} else {
			r = m - 1
			ans = m
		}
	}
	return
}

/*
快慢指针（环的入口）
i: 0 1 2 3 4
   1 3 4 2 2

slow: 0 1 3 2 4
fast: 0 3 4 4 4

slow: 0 1 3 2
fast: 4 2 4 2

*/
func findDuplicate2(nums []int) (ans int) {
	s, f := 0, 0
	for s, f = nums[s], nums[nums[f]]; s != f; s, f = nums[s], nums[nums[f]] {
	}
	// s == l 此时是环的入口
	s = 0
	for s != f {
		s = nums[s]
		f = nums[f]
	}
	return s
}
