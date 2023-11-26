package main

import "fmt"

func maxSubarrays(nums []int) (cnt int) {
	n := len(nums)
	sum := nums[0]
	for i := 1; i < n; i++ {
		sum &= nums[i]
		if sum == 0 {
			sum = nums[(i+1)%n]
			cnt += 1
		}
	}
	if cnt != 0 {
		return cnt
	}
	return 1
}

func main() {
	nums1 := []int{1, 0, 2, 0, 1, 2}
	fmt.Println(maxSubarrays(nums1)) // 输出：3

	nums2 := []int{5, 7, 1, 3}
	fmt.Println(maxSubarrays(nums2)) // 输出：1
}
