package main

// dpmax[i] = max(dpmax[i - 1] * nums[i], dpmin[i-1]*nums[i], nums[i])
// dpmin[i] = max(dpmin[i - 1] * nums[i], dpmax[i-1]*nums[i], nums[i])
func maxProduct(nums []int) int {
	dpmax, dpmin, ans := nums[0], nums[0], nums[0]
	for i := 1; i < len(nums); i++ {
		_dpmax, _dpmin := dpmax, dpmin
		dpmax = max(_dpmax*nums[i], max(_dpmin*nums[i], nums[i]))
		dpmin = max(_dpmin*nums[i], max(_dpmax*nums[i], nums[i]))
		ans = max(dpmin, dpmax)
	}
	return ans
}
