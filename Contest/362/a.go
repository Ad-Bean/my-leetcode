package main

import (
	"fmt"
	"sort"
)

func numberOfPoints(nums [][]int) (ans int) {
	sort.Slice(nums, func(i, j int) bool {
		return nums[i][0] < nums[j][0]
	})

	fmt.Printf("%v\n", nums)
	curMax := nums[0][1]
	n := len(nums)
	ans = nums[0][1] - nums[0][0] + 1
	for i := 1; i < n; i++ {
		if nums[i][0] <= curMax {
			if nums[i][1] >= curMax {
				ans += nums[i][1] - curMax
				curMax = nums[i][1]
			}
		} else {
			ans += nums[i][1] - nums[i][0] + 1
			if nums[i][1] >= curMax {
				curMax = nums[i][1]
			}
		}
	}
	return
}

func main() {
	nums := [][]int{
		// {2, 5}, {3, 8}, {1, 6}, {4, 10},
		// {3, 6}, {1, 5}, {4, 7},
		{4, 4}, {9, 10}, {9, 10}, {3, 8},
	}
	ans := numberOfPoints(nums)
	fmt.Printf("%v\n", ans)

}

/*
[[3 8] [4 4] [9 10] [9 10]]


8-3+1 = 6

[[2,5],[3,8],[1,6],[4,10]]


[[1 6] [2 5] [3 8] [4 10]]

6-1+1 = 6


*/
