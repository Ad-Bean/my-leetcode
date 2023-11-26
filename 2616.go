package main

import "sort"

// 看到「最大化最小值」或者「最小化最大值」就要想到二分答案，这是一个固定的套路。
func minimizeMax(nums []int, p int) int {
	sort.Ints(nums)
	return sort.Search(1e9, func(mx int) bool {
		cnt := 0
		for i := 0; i < len(nums)-1; i++ {
			if nums[i+1]-nums[i] <= mx {
				cnt++
				i++
			}
		}
		return cnt >= p
	})
}
