package main

func combinationSum(candidates []int, target int) (ans [][]int) {
	path := []int{}
	n := len(candidates)
	var dfs func(int, int)
	dfs = func(i, t int) {
		if i == n {
			return
		}
		if t == 0 {
			ans = append(ans, append([]int{}, path...))
			return
		}
		dfs(i+1, t)
		if t-candidates[i] >= 0 {
			path = append(path, candidates[i])
			dfs(i, t-candidates[i])
			path = path[:len(path)-1]
		}
	}
	dfs(0, target)
	return
}
