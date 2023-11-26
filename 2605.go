package main

func minNumber(nums1 []int, nums2 []int) int {
	same := func() int {
		mp := map[int]bool{}
		ans := 0x3f3f
		for _, num := range nums1 {
			mp[num] = true
		}
		for _, num := range nums2 {
			_, ok := mp[num]
			if ok {
				ans = min(ans, num)
			}
		}
		if ans == 0x3f3f {
			return -1
		}
		return ans
	}
	both := same()
	if both != -1 {
		return both
	}
	a, b := nums1[0], nums2[0]
	for i := range nums1 {
		a = min(a, nums1[i])
	}
	for i := range nums1 {
		b = min(b, nums1[i])
	}
	return min(a*10+b, b*10+a)
}
