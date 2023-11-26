package main

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	// min := func (a, b int) int {if a < b { return a }; return b}
	n, m := len(nums1), len(nums2)
	getKth := func(k int) int {
		idx1, idx2 := 0, 0
		for {
			if idx1 == n {
				return nums2[idx2+k-1]
			}
			if idx2 == m {
				return nums1[idx1+k-1]
			}
			if k == 1 {
				return min(nums1[idx1], nums2[idx2])
			}
			m := k / 2
			nidx1 := min(idx1+m, n) - 1
			nidx2 := min(idx2+m, m) - 1
			p1, p2 := nums1[idx1], nums2[idx2]
			if p1 <= p2 {
				k -= (nidx1 - idx1 + 1)
				idx1 = nidx1 + 1
			} else {
				k -= (nidx2 - idx2 + 1)
				idx2 = nidx2 + 1
			}
		}
		return 0
	}
	tot := len(nums1) + len(nums2)
	if tot&1 == 1 {
		m := tot / 2
		return float64(getKth(m + 1))
	} else {
		m1, m2 := tot/2-1, tot/2
		return float64(getKth(m1+1)+getKth(m2+1)) / 2.0
	}
	return 0
}
