package main

import "fmt"

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func lengthOfLongestSubsequence(nums []int, target int) int {
	dp := make([]int, target+1)
	for i := range dp {
		dp[i] = -1
	}

	dp[0] = 0
	maxLength := -1
	for _, num := range nums {
		for j := target; j >= num; j-- {
			if dp[j-num] != -1 {
				dp[j] = max(dp[j], dp[j-num]+1)
				maxLength = max(maxLength, dp[j])
			}
		}
	}

	return dp[target]
}

func main() {
	nums1 := []int{5, 4, 3, 2, 1}
	target1 := 9
	fmt.Println("输入:", nums1, target1)
	fmt.Println("输出:", lengthOfLongestSubsequence(nums1, target1)) // 3

	nums2 := []int{4, 1, 3, 2, 1, 5}
	target2 := 7
	fmt.Println("输入:", nums2, target2)
	fmt.Println("输出:", lengthOfLongestSubsequence(nums2, target2)) // 4

	nums3 := []int{1, 1, 5, 4, 5}
	target3 := 3
	fmt.Println("输入:", nums3, target3)
	fmt.Println("输出:", lengthOfLongestSubsequence(nums3, target3)) // -1
}
