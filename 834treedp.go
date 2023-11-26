package main

/*
    0
  1   2
    3 4 5

*/
// dp[i][j] => node_i 到 node_j 的距离
// dp[0][0] = 0
// dp[0][1] = 1
// dp[0][2] = 1
// dp[0][3] = 2
// dp[2][0] = 1 = dp[0][0] + 1
// dp[2][1] = 2 = dp[2][0] + dp[0][1]
func sumOfDistancesInTree(n int, edges [][]int) []int {

}
