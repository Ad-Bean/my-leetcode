package main

func minimumSum(nums []int) int {
	n := len(nums)
	preMax := nums[0]
	sum := 0x3f3f3f3f
	for i := 1; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if preMax < nums[i] && nums[i] > nums[j] {
				sum = min(sum, preMax+nums[i]+nums[j])
			}
		}
		if preMax > nums[i] {
			preMax = nums[i]
		}
	}
	if sum != 0x3f3f3f3f {
		return sum
	}
	return -1
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
