package main

func minimumReplacement(nums []int) (ans int64) {
	n := len(nums)
	m := nums[n-1]
	for i := n - 2; i >= 0; i-- {
		step := nums[i] / m
		ans += int64(step)
		m = nums[i] / step
	}
	return
}
