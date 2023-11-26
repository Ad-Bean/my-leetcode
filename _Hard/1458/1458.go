package main

/*
f[i][j] 表示 nums1 前 i 个元素和 nums2 前 j 个元素

f[i][j] = max(f[i-1][j-1])
*/
func maxDotProduct(nums1 []int, nums2 []int) int {
	m, n := len(nums1), len(nums2)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			f[i][j] = nums1[i] * nums2[j]
			if i > 0 {
				f[i][j] = max(f[i][j], f[i-1][j])
			}
			if j > 0 {
				f[i][j] = max(f[i][j], f[i][j-1])
			}
			if i > 0 && j > 0 {
				f[i][j] = max(f[i][j], f[i-1][j-1]+f[i][j])
			}
		}
	}
	return f[m-1][n-1]
}
