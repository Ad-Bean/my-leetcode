package main

func findMin(nums []int) int {
	l, r := 0, len(nums)-1
	for l < r {
		m := l + (r-l)/2
		if nums[m] < nums[r] {
			r = m
		} else if nums[m] > nums[r] {
			l = m + 1
		} else {
			r = r - 1
		}
	}
	return nums[l]
}

// 1,3,3
// l=0, r=2    m=1
// l=0, r=1    m=0
// l=0, r=0

/*
func findMin(nums []int) int {
	l, r := 0, len(nums)-2
	for l <= r {
		m := l + (r-l)/2
		if nums[m] < nums[r+1] {
			r = m - 1
		} else if nums[m] > nums[r+1] {
			l = m + 1
		} else {
			r = r - 1
		}
	}
	return nums[l]
}
*/
