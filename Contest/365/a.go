package main

func maximumTripletValue(nums []int) int64 {
	maxSum := int64(0)
	for k := range nums {
		for j := 1; j < k; j++ {
			for i := 0; i < j; i++ {
				maxSum = max(maxSum, int64(nums[i]-nums[j])*int64(nums[k]))
			}
		}
	}
	return maxSum
}
