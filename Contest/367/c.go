package main

/*
		5 1 4 1
preMax  5 5 5 5
preMin  5 1 1 1

i = 2
*/

// func max(a,b int) int {if a > b {return a}; return b}
// func min(a,b int) int {if a > b {return b}; return a}
func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
func findIndices(nums []int, indexDifference int, valueDifference int) []int {
	n := len(nums)
	type pair struct{ val, idx int }
	preMax, preMin := make([]pair, n), make([]pair, n)
	preMax[0], preMin[0] = pair{nums[0], 0}, pair{nums[0], 0}
	for i := 1; i < n; i++ {
		if nums[i] > preMax[i-1].val {
			preMax[i] = pair{nums[i], i}
		} else {
			preMax[i] = preMax[i-1]
		}
		if nums[i] < preMin[i-1].val {
			preMin[i] = pair{nums[i], i}
		} else {
			preMin[i] = preMin[i-1]
		}
	}
	for i := indexDifference; i < n; i++ {
		j := i - indexDifference
		if abs(nums[i]-preMax[j].val) >= valueDifference {
			return []int{preMax[j].idx, i}
		}
		if abs(nums[i]-preMin[j].val) >= valueDifference {
			return []int{preMin[j].idx, i}
		}
	}
	return []int{-1, -1}
}
