package main

import "fmt"

func combine(n int, k int) (ans [][]int) {
	path := []int{}
	var dfs func(int)
	dfs = func(i int) {
		if len(path) == k {
			ans = append(ans, append([]int{}, path...))
			return
		}
		if i > n {
			return
		}
		path = append(path, i)
		dfs(i + 1)
		path = path[:len(path)-1]

		dfs(i + 1)
	}
	dfs(1)
	return
}

func main() {
	n, k := 4, 2
	fmt.Printf("%v\n", combine(n, k))
}
