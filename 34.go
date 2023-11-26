package main

import "fmt"

// [l, r]
// [l, m] [m, r] for l <= r: l = m + 1, r = m - 1

// l, r := 0, len(nums)-1
// for l <= r {
// 	m := l + (r-l)/2
// 	if nums[m] < target {
// 		l = m + 1
// 	} else {
// 		r = m - 1
// 	}
// 	return l
// }
func searchRange(nums []int, target int) []int {
	// [l, r)
	// [l, m) [m, r) -> for l < r: l = m + 1, r = m
	lower_bound := func(t int) int {
		l, r := 0, len(nums)
		for l < r {
			m := l + (r-l)/2
			if nums[m] < t {
				l = m + 1
			} else {
				r = m
			}
		}
		fmt.Printf("%d %d\n", l, r)
		return l
	}
	st := lower_bound(target)
	if st == len(nums) || nums[st] != target {
		return []int{-1, -1}
	}
	en := lower_bound(target+1) - 1
	return []int{st, en}
}
func main() {
	nums := []int{5, 7, 7, 8, 8, 10}
	target := 8
	_ = searchRange(nums, target)
}

/*
[5,7,7,8,8,10], t=8

n = 6
l, r = 0, 6
m = 3



*/
