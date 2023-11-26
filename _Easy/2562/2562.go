package main

import "strconv"

func findTheArrayConcVal(nums []int) (ans int64) {
	l, r := 0, len(nums)-1
	for l < r {
		num, _ := strconv.Atoi(strconv.Itoa(nums[l]) + strconv.Itoa(nums[r]))
		ans += int64(num)
		l, r = l+1, r-1
	}
	if l == r {
		ans += int64(nums[l])
	}
	return
}
