package main

import "fmt"

func alternateDigitSum(n int) int {
	nums := []int{}
	for n > 0 {
		nums = append(nums, n%10)
		n /= 10
	}
	cnt, flag := 0, 1
	for i := len(nums) - 1; i >= 0; i-- {
		cnt += flag * nums[i]
		flag *= -1
	}
	return cnt
}

func main() {
	n := 886996
	ans := alternateDigitSum(n)
	fmt.Printf("%d\n", ans)
}
