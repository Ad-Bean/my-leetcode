package main

import (
	"fmt"
)

// 而这样的「连续段 偶奇 两两成对」的组合，适合使用「异或」来找相应的成组对象
// 奇数 mid ^ 1 = mid + 1, 偶数 mid ^ 1 = mid
func singleNonDuplicate(nums []int) int {
	n := len(nums)
	l, r := 0, n-1
	for l < r {
		fmt.Printf("%d %d %d\n", l, r, (l+r)/2)
		m := (l + r) >> 1
		if nums[m] == nums[m^1] {
			l = m + 1
		} else {
			r = m
		}
	}
	return nums[r]
}

func main() {
	nums := []int{1, 1, 3, 3, 4, 4, 8, 8, 9}
	res := singleNonDuplicate(nums)
	fmt.Printf("%d\n", res)

}
