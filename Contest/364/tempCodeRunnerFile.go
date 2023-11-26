func maximumSumOfHeights(maxHeights []int) (sum int64) {
	min := func(a, b int64) int64 {
		if a < b {
			return a
		}
		return b
	}
	sum = 0x3f3f3f3f3f3f3f3f
	n := len(maxHeights)
	for i, height := range maxHeights {
		maxSum := int64(0)
		prev := int64(height)
		for j, r := range maxHeights[i:] {
			if j > 0 {
				prev = min(int64(r), min(prev, int64(maxHeights[j-1])))
			} else {
				prev = min(prev, int64(r))
			}
			maxSum += int64(r) - prev
		}
		next := int64(height)
		for j := i - 1; j >= 0; j-- {
			if j+1 < n {
				next = min(min(next, int64(maxHeights[j])), int64(maxHeights[j+1]))
			} else {
				next = min(next, int64(maxHeights[j]))
			}
			maxSum += int64(maxHeights[j]) - next
		}
		sum = min(sum, maxSum)
	}
	return
}