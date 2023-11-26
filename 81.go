package main

func search(nums []int, target int) bool {
	n := len(nums)
	if n == 1 {
		return nums[0] == target
	}

	l, r := 0, n-1
	for l <= r {
		m := l + (r-l)/2
		if nums[m] == target {
			return true
		}
		if nums[l] == nums[m] && nums[m] == nums[r] {
			l, r = l+1, r-1
		} else if nums[l] <= nums[m] {
			if nums[l] <= target && target <= nums[m] {
				r = m - 1
			} else {
				l = m + 1
			}
		} else {
			if nums[m] < target && target <= nums[n-1] {
				l = m + 1
			} else {
				r = m - 1
			}
		}
	}
	return false
}
