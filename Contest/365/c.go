package main

import "fmt"

func minSizeSubarray(nums []int, t int) int {
	min := func(a, b int) int {
		if a < b {
			return a
		}
		return b
	}
	sum := 0
	for _, num := range nums {
		sum += num
	}
	n := len(nums)
	ans, cnt := t/sum*n, t/sum
	t = t - cnt*sum
	if t == 0 {
		return ans
	}
	nums = append(nums, nums...)
	pre := make([]int, 2*n+1)
	mp := map[int]int{}
	end := 0x3f3f3f3f
	for i := 1; i <= 2*n; i++ {
		pre[i] = pre[i-1] + nums[i-1]
		tt := pre[i] - t
		if mp[tt] != 0 {
			end = min(end, i-mp[tt])
		}
		mp[pre[i]] = i
	}
	if end < 0x3f3f3f3f {
		return ans + end
	}
	return -1
}

func main() {
	a := []int{1, 2, 3, 4}
	fmt.Printf("%v\n", append(a, a...))
}

/*
2,1,5,7,7,1,6,3    2,1,5,7,7,1,6,3

*/
