package main

import "fmt"

/*
核心思想：把矩阵拉成一维的，我们需要算出每个数左边所有数的乘积，以及右边所有数的乘积，这都可以用递推得到。


从 grid[i][j] 的下一个元素开始，到最后一个元素 grid[n−1][m−1] 的乘积，
记作 suf[i][j]。这可以从最后一行最后一列开始，倒着遍历得到


然后算出从第一个元素 grid[0][0] 开始，到 grid[i][j] 的上一个元素的乘积，
记作 pre[i][j]。这可以从第一行第一列开始，正着遍历得到。


p[i][j] = pre[i][j]⋅suf[i][j]
*/

func constructProductMatrix(grid [][]int) [][]int {
	const mod = 12345
	n, m := len(grid), len(grid[0])
	ans := make([][]int, n)
	suf := 1
	for i := n - 1; i >= 0; i-- {
		ans[i] = make([]int, n)
		for j := m - 1; j >= 0; j-- {
			ans[i][j] = suf
			suf = suf * grid[i][j] % mod
		}
	}

	pre := 1
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			ans[i][j] = pre * ans[i][j] % mod
			pre = pre * grid[i][j] % mod
		}
	}
	return ans
}

func main() {
	grid := [][]int{{12345}, {2}, {1}}
	fmt.Printf("%v\n", constructProductMatrix(grid))
}
