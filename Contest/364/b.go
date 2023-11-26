package main

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
func max(a, b int64) int64 {
	if a < b {
		return b
	}
	return a
}
func maximumSumOfHeights(maxHeights []int) (sum int64) {
	n := len(maxHeights)
	for i := range maxHeights {
		maxSum := int64(maxHeights[i])
		left := int64(maxHeights[i])
		for j := i - 1; j >= 0; j-- {
			if j+1 < n {
				left = min(left, min(int64(maxHeights[j+1]), int64(maxHeights[j])))
			} else {
				left = min(left, int64(maxHeights[j]))
			}
			maxSum += left
		}
		right := int64(maxHeights[i])
		for j := i + 1; j < n; j++ {
			if j > 0 {
				right = min(right, min(int64(maxHeights[j]), int64(maxHeights[j-1])))
			} else {
				right = min(right, int64(maxHeights[j]))
			}
			maxSum += right
		}

		sum = max(sum, maxSum)
	}
	return
}
