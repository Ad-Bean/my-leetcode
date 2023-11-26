package main

func maxNonDecreasingLength(nums1 []int, nums2 []int) int {
	n := len(nums1)
	ans := 1
	nums := [2][]int{nums1, nums2}

	f := make([][2]int, n)
	f[0] = [2]int{1, 1}
	for i := 1; i < n; i++ {
		f[i] = [2]int{1, 1}
		for j := 0; j < 2; j++ {
			if nums1[i-1] <= nums[j][i] {
				f[i][j] = f[i-1][0] + 1
			}
			if nums2[i-1] <= nums[j][i] {
				f[i][j] = max(f[i][j], f[i-1][1]+1)
			}
		}
		ans = max(ans, max(f[i][0], f[i][1]))
	}
	return ans
}
