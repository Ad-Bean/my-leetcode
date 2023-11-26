package main

func merge(nums1 []int, m int, nums2 []int, n int) {
	l, r := m-1, n-1
	cur := m + n - 1
	for r >= 0 {
		if l >= 0 && nums1[l] > nums2[r] {
			nums1[cur] = nums1[l]
			l--
		} else {
			nums1[cur] = nums2[r]
			r--
		}
		cur--
	}
}
