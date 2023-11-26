package main

import (
	"fmt"
)

func maximumSum(nums []int) (ret int64) {
	ans := map[int]int64{}
	for i := range nums {
		x, j, k := i+1, 1, 1
		// x 是下标 i+1，比如 1，2，3，4，5
		// 枚举直到 i+1 的完全平方数，用 j 记录
		for k*k <= x {
			if x%(k*k) == 0 {
				j = k
			}
			k += 1
		}
		// x /= j*j 表示 ?
		x /= j * j
		if _, ok := ans[x]; !ok {
			ans[x] = 0
		}
		ans[x] += int64(nums[i])
	}
	for _, v := range ans {
		if v > ret {
			ret = v
		}
	}
	return
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	nums1 := []int{8, 7, 3, 5, 7, 2, 4, 9}
	fmt.Println(maximumSum(nums1)) // 输出：16

	nums2 := []int{5, 10, 3, 10, 1, 13, 7, 9, 4}
	fmt.Println(maximumSum(nums2)) // 输出：19
}
