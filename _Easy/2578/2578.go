package main

import (
	"fmt"
	"sort"
)

func splitNum(num int) int {
	nums := []int{}
	for num > 0 {
		nums = append(nums, num%10)
		num /= 10
	}
	sort.Ints(nums)
	n := len(nums)
	num1, num2 := 0, 0
	i := 0
	for ; i < n; i += 2 {
		if i < n-1 {
			num1, num2 = num1+nums[i], num2+nums[i+1]
			if i != n-2 {
				num1 *= 10
				if i+1 != n-2 {
					num2 *= 10
				}
			}
		} else {
			num1 += nums[i]
		}
	}
	fmt.Printf("%d %d\n", num1, num2)
	return num1 + num2
}

/*

2 3 4 5

6 7 8
*/

func main() {
	num := 4325
	fmt.Printf("%d\n", splitNum(num))
	num = 687
	fmt.Printf("%d\n", splitNum(num))
}
