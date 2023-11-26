package main

func numSubarrayProductLessThanK(nums []int, k int) (ans int) {
	if k <= 1 {
		return 0
	}
	l, mul := 0, 1
	for r, num := range nums {
		mul *= num
		for mul >= k {
			mul /= nums[l]
			l++
		}
		ans += r - l + 1
	}
	return
}
