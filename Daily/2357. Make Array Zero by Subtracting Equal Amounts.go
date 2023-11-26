package main

import "sort"

func minimumOperations(nums []int) int {
	sort.Ints(nums)
	ans := 0
	for i, num := range nums {
		if num > 0 {
			subtract(nums, num, i)
			ans++
		}
	}
	return ans
}

func subtract(nums []int, num, idx int) {
	for i := idx; i < len(nums); i++ {
		nums[i] -= num
	}
}

// Hash
func minimumOperationsHash(nums []int) int {
	set := map[int]struct{}{}
	for _, num := range nums {
		if num > 0 {
			set[num] = struct{}{}
		}
	}
	return len(set)
}
