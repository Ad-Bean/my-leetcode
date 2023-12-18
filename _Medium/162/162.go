package main

func findPeakElement(nums []int) int {
	l, r := 0, len(nums)-1
	for l < r {
		m := l + (r-l)/2
		if nums[m] < nums[m+1] {
			l = m + 1
		} else {
			r = m
		}
	}
	return r
}

// 1,2,3,1
// l=0, r=3
// l=2, r=3
// l=3, r=3

// 1,2,1,3,5,6,4
/*
l=0, r=6
l=4, r=6
l=4, r=5
l=5, r=5

*/
