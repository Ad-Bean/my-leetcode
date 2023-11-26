package main

func maxAbsoluteSum(nums []int) (ans int) {
	maxf := -0x3f3f3f3f
	minf := 0x3f3f3f3f
	for _, num := range nums {
		maxf = max(maxf, 0) + num
		minf = min(minf, 0) + num
		ans = max(ans, max(maxf, -minf))
	}
	return
}
