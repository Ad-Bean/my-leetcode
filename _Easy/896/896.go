package main

/*
1. 两次遍历
求出 isASC

2. 一次遍历
如果遇到了 nums[i] > nums[i + 1] 又遇到了 nums[j] < nums[j + 1] 则返回false
*/
func isMonotonic(nums []int) bool {
	isAsc, isDesc := true, true
	for i := 1; i < len(nums); i++ {
		if nums[i-1] < nums[i] {
			isDesc = false
		}
		if nums[i-1] > nums[i] {
			isAsc = false
		}
	}
	return isDesc || isAsc
}
