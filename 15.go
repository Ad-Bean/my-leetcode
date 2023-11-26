package main

import (
	"fmt"
	"sort"
)

func threeSum(nums []int) (ans [][]int) {
	n := len(nums)
	sort.Ints(nums)
	for i := 0; i < n-2; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		num1 := nums[i]
		// op1:
		if num1+nums[i+1]+nums[i+2] > 0 {
			break
		}
		// op2:
		if num1+nums[n-2]+nums[n-1] < 0 {
			continue
		}
		l, r := i+1, n-1
		for l < r {
			num2, num3 := nums[l], nums[r]
			if num1+num2+num3 == 0 {
				ans = append(ans, []int{num1, num2, num3})
				l, r = l+1, r-1
				for l < r && nums[l] == nums[l-1] {
					l++
				}
			} else if num1+num2+num3 < 0 {
				l++
			} else {
				r--
			}
		}
	}
	return
}

func main() {
	// -1, -1, 0, 1
	nums := []int{-2, 0, 0, 2, 2}
	ans := threeSum(nums)
	fmt.Printf("%v\n", ans)
}
