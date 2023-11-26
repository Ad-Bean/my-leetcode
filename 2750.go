package main

func numberOfGoodSubarraySplits(nums []int) int {
	last, ans := -1, 1
	for i, num := range nums {
		if num == 1 {
			if last != -1 {
				ans = (i - last) * ans % (1e9 + 7)
			}
			last = i
		}
	}
	if last != -1 {
		return ans
	}
	return 0
}
