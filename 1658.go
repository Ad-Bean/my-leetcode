package main

/*
滑动窗口
nums 去掉一个最长子数组，剩余元素和为 x
找到最长子数组和为 sum - x

*/
func minOperations(nums []int, x int) int {
	target := -x
	for _, num := range nums {
		target += num
	}
	if target < 0 {
		return -1
	}

	ans, l, curSum := -1, 0, 0
	for r, num := range nums {
		curSum += num
		if curSum > target {
			curSum, l = curSum-nums[l], l+1
		}
		if curSum == target {
			ans = max(ans, r-l+1)
		}
	}
	if ans == -1 {
		return ans
	}
	return len(nums) - ans
}
