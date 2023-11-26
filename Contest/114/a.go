package main

func minOperations(nums []int, k int) int {
	mp := map[int]int{}
	n := len(nums)
	for i := n - 1; i >= 0; i-- {
		mp[nums[i]]++
		flag := true
		for i := 1; i <= k; i++ {
			if mp[i] == 0 {
				flag = false
			}
		}
		if flag {
			return n - i
		}
	}
	return n
}
