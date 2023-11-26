package main

func minSum(nums1 []int, nums2 []int) int64 {
	sum1, sum2 := int64(0), int64(0)
	cnt1, cnt2 := int64(0), int64(0)
	for _, num := range nums1 {
		if num == 0 {
			cnt1++
		}
		sum1 += int64(num)
	}
	for _, num := range nums2 {
		if num == 0 {
			cnt2++
		}
		sum2 += int64(num)
	}
	if cnt1 == 0 && cnt2 == 0 {
		if sum1 == sum2 {
			return sum1
		}
		return -1
	} else if cnt1 != 0 && cnt2 == 0 {
		if sum2 >= sum1+cnt1 {
			return sum2
		}
		return -1
	} else if cnt1 == 0 && cnt2 != 0 {
		if sum1 >= sum2+cnt2 {
			return sum1
		}
		return -1
	} else {
		return max(sum1+cnt1, sum2+cnt2)
	}
}
