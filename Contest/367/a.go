package main

/*
0 1 1 1 1 2 3 3 3 4
*/

func findIndicesAAAAAAA(nums []int, indexDifference int, valueDifference int) []int {
	// abs := func(a int) int {if a< 0 {return -a};return a}
	for i := range nums {
		for j := i; j < len(nums); j++ {
			if j-i >= indexDifference && abs(nums[j]-nums[i]) >= valueDifference {
				return []int{i, j}
			}
		}
	}
	return []int{-1, -1}
}
