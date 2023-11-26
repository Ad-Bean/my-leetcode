package main

func moveZeroes(nums []int) {
	l, r, n := 0, 0, len(nums)
	for r < n {
		if nums[r] != 0 {
			nums[l], nums[r] = nums[r], nums[l]
			l++
		}
		r++
	}
}
