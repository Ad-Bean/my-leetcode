package main

import "strconv"

func summaryRanges(nums []int) (ans []string) {
	for i, n := 0, len(nums); i < n; {
		l := i
		for i++; i < n && nums[i-1]+1 == nums[i]; i++ {
		}
		s := strconv.Itoa(nums[l])
		if l < i-1 {
			s += "->" + strconv.Itoa(nums[i-1])
		}
		ans = append(ans, s)
	}
	return
}
