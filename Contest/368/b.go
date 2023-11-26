package main

import "fmt"

func minimumSum(nums []int) int {
	n := len(nums)
	preMax := nums[0]
	sufMin := make([]int, n)
	sufMin[n-1] = nums[n-1]
	for i := n - 2; i >= 0; i-- {
		if nums[i] < sufMin[i+1] {
			sufMin[i] = nums[i]
		} else {
			sufMin[i] = sufMin[i+1]
		}
	}
	fmt.Printf("%v\n", sufMin)
	sum := 0x3f3f3f3f
	for i := 1; i < n; i++ {
		if preMax < nums[i] && nums[i] > sufMin[i] {
			sum = min(sum, preMax+nums[i]+sufMin[i])
		}
		if preMax > nums[i] {
			preMax = nums[i]
		}
	}
	if sum != 0x3f3f3f3f {
		return sum
	}
	return -1
}

func main() {
	nums := []int{8, 6, 1, 5, 3}
	fmt.Printf("%d\n", minimumSum(nums))
}
