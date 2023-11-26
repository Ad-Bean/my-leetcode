package main

import (
	"sort"
)

func threeSumClosest(nums []int, target int) (ans int) {
	sort.Ints(nums)
	n, minn := len(nums), 0x3f3f3f3f
	for i, x := range nums[:n-2] {
		if i > 0 && x == nums[i-1] {
			continue
		}

		sum := x + nums[i+1] + nums[i+2]
		if sum > target {
			if sum-target < minn {
				ans = sum
			}
			break
		}

		sum = x + nums[n-1] + nums[n-2]
		if sum < target {
			if target-sum < minn {
				minn = target - sum
				ans = sum
			}
			continue
		}

		j, k := i+1, n-1
		for j < k {
			sum = x + nums[j] + nums[k]
			if sum == target {
				return target
			}
			if sum > target {
				if sum-target < minn {
					minn = sum - target
					ans = sum
				}
				k--
			} else {
				if target-sum < minn {
					minn = target - sum
					ans = sum
				}
				j++
			}
		}
	}
	return
}
