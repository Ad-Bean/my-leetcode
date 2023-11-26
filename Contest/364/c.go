func maximumSumOfHeights(maxHeights []int) (ans int64) {
	n := len(maxHeights)
	stk1 := [][]int{{maxHeights[0], 1}}
	stk2 := [][]int{{maxHeights[n-1], 1}}
	left, right := make([]int, n), make([]int, n)
	for i := 1; i < n; i++ {
		curVal, curCnt := maxHeights[i], 1
		for len(stk1) > 0 && stk1[len(stk1)-1][0] >= curVal {
			pre := stk1[len(stk1)-1]
			stk1 = stk1[:len(stk1)-1]
			left[i] += (pre[0] - curVal) * pre[1]
			curCnt += pre[1]
		}
		stk1 = append(stk1, []int{curVal, curCnt})
		left[i] += left[i-1]
	}
	for i := n - 2; i >= 0; i-- {
		curVal, curCnt := maxHeights[i], 1
		for len(stk2) > 0 && stk2[len(stk2)-1][0] >= curVal {
			pre := stk2[len(stk2)-1]
			stk2 = stk2[:len(stk2)-1]
			right[i] += (pre[0] - curVal) * pre[1]
			curCnt += pre[1]
		}
		stk2 = append(stk2, []int{curVal, curCnt})
		right[i] += right[i+1]
	}
	maxSum := int64(0)
	for _, h := range maxHeights {
		maxSum += int64(h)
	}
	for i := 0; i < n; i++ {
		if i+1 < n {
			ans = max(ans, maxSum-int64(left[i])-int64(right[i+1]))
		} else {
			ans = max(ans, maxSum-int64(left[i]))
		}
	}
	return
}
func max(a, b int64) int64 {
	if a < b {
		return b
	}
	return a
}