package main

func permute(nums []int) [][]int {
	n := len(nums)
	var ans [][]int
	path, onPath := make([]int, n), make([]bool, n)
	var dfs func(int)
	dfs = func(i int) {
		if i == n {
			ans = append(ans, path)
			return
		}
		for j, on := range onPath {
			if !on {
				path[i] = nums[j]
				onPath[j] = true
				dfs(i + 1)
				onPath[j] = false
			}
		}
	}
	dfs(0)
	return ans
}
