package main

import "fmt"

func missingNumber(nums []int) int {
	for i, num := range nums {
		if num != i {
			return i
		}
	}
	return len(nums)
}

func binarySearchMissingNumber(nums []int) int {
	res := -1
	l, r := 0, len(nums)-1
	for l <= r {
		m := l + (r-l)/2
		if m == nums[m] {
			l = m + 1
		} else {
			res = m
			r = m - 1
		}
	}
	if res == -1 {
		return len(nums)
	} else {
		return res
	}
}

func main() {
	fmt.Println("Hello World!")
}
