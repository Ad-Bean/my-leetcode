package main

import "fmt"

// all nums are in [0, n-1]
// make nums[i] == i
func findRepeatNumber(nums []int) int {
	i, n := 0, len(nums)
	for i < n {
		if nums[i] == i {
			i++
			continue
		}
		if nums[nums[i]] == nums[i] {
			return nums[i]
		}
		nums[i], nums[nums[i]] = nums[nums[i]], nums[i]
	}
	return -1
}

func main() {
	fmt.Println("Hello World!")
}
