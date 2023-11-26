package main

func minLengthAfterRemovals(nums []int) int {
	l := 0
	n := len(nums)
	ans := n
	for r := (n + 1) / 2; r < n; r++ {
		if l != r && nums[l] < nums[r] {
			l++
			ans -= 2
		}
	}
	return ans
}
