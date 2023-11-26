package main

import "fmt"

func maximumPoints(edges [][]int, coins []int, k int) int {
	n := len(coins)
	graph := make([][]int, n)
	for _, edge := range edges {
		u, v := edge[0], edge[1]
		graph[u] = append(graph[u], v)
		graph[v] = append(graph[v], u)
	}

	dp := make([][2]int, n)
	var dfs func(node, parent int)
	dfs = func(node, parent int) {
		dp[node][0] = coins[node] - k
		lost := 0
		if coins[node]-k < 0 {
			lost = k - coins[node]
		}
		dp[node][1] = coins[node] / 2

		for _, child := range graph[node] {
			if child == parent {
				continue
			}
			dfs(child, node)
			dp[node][0] += max(dp[child][0]-lost, dp[child][1])
			dp[node][1] += max(dp[child][0], dp[child][1])
		}
	}

	dfs(0, -1)
	fmt.Printf("%v\n", dp)
	return max(dp[0][0], dp[0][1])
}

func main() {
	edges := [][]int{{0, 1}, {1, 2}, {2, 3}}
	coins := []int{10, 10, 3, 3}
	k := 5
	fmt.Printf("%d\n", maximumPoints(edges, coins, k))
}
