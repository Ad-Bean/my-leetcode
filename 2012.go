package main

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}
func sumOfBeauties(nums []int) (ans int) {
	n := len(nums)
	sufMin := make([]int, n)
	sufMin[n-1] = nums[n-1]
	for i := n - 2; i > 1; i-- {
		sufMin[i] = min(sufMin[i+1], nums[i])
	}
	preMax := nums[0]
	for i := 1; i < n-1; i++ {
		if preMax < nums[i] && nums[i] < sufMin[i+1] {
			ans += 2
		} else if nums[i-1] < nums[i] && nums[i] < nums[i+1] {
			ans += 1
		}

		if nums[i] > preMax {
			preMax = nums[i]
		}
	}
	return
}
