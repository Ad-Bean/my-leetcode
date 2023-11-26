package main

func findMin(nums []int) int {
	l, r := 0, len(nums)-1
	for l < r {
		m := l + (r-l)/2
		if nums[m] < nums[len(nums)-1] {
			r = m
		} else {
			l = m + 1
		}
	}
	return nums[l]
}

// 两段或一段升序

// 开区间
// 3,4,5,1,2
// l=0, r=4
// l=3, r=4
// l=3, r=3

// 闭区间
// 0,4
// 3,4
// 3,3
// 3,2
