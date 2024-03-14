package main

func maxArrayValue(nums []int) int64 {
	n := len(nums)
	maxx := int64(nums[n-1])
	for i := n - 1; i >= 0; i-- {
		if int64(nums[i]) <= maxx {
			maxx += int64(nums[i])
		} else {
			maxx = int64(nums[i-1])
		}
	}
	return maxx
}
