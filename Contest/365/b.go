package main

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func maximumTripletValue(nums []int) (ans int64) {
	n := len(nums)
	lmax, curSum := int64(0), int64(0)
	for i := 0; i < n; i++ {
		ans = max(ans, curSum*int64(nums[i]))
		curSum = max(curSum, lmax-int64(nums[i]))
		lmax = max(lmax, int64(nums[i]))
	}
	return
}

/*
nums[i] - nums[j] 的最大值

*/
