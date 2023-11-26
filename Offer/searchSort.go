package main

import (
	"fmt"
)

func search(nums []int, target int) int {
	l := binarySearch(nums, target, true)
	r := binarySearch(nums, target, false) - 1
	if l <= r && r < len(nums) && nums[l] == target {
		return r - l + 1
	}

	return 0
}

// func search(nums []int, target int) int {
// 	leftmost := sort.SearchInts(nums, target)
// 	if leftmost == len(nums) || nums[leftmost] != target {
// 		return 0
// 	}
// 	rightmost := sort.SearchInts(nums, target+1) - 1
// 	return rightmost - leftmost + 1
// }

func binarySearch(nums []int, target int, lower bool) int {
	l, r := 0, len(nums)-1
	ans := len(nums)
	for l <= r {
		m := l + (r-l)/2
		if nums[m] > target || (lower && nums[m] >= target) {
			r = m - 1
			ans = m
		} else {
			l = m + 1
		}
	}

	return ans
}

func main() {
	fmt.Println("Hello World!")
}
