package main

func removeDuplicates(nums []int) int {
	n := len(nums)
	if n <= 2 {
		return n
	}
	l, r := 2, 2
	for r < n {
		if nums[l-2] != nums[r] {
			nums[l] = nums[r]
			l++
		}
		r++
	}
	return l
}
