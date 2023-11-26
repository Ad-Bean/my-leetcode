package main

import (
	"bits"
	"fmt"
)

func canMakePaliQueries(s string, queries [][]int) []bool {
	pre := make([]uint32, len(s)+1)
	for i, c := range s {
		bit := uint32(1) << (c - 'a')
		pre[i+1] = pre[i] ^ bit
	}
	ans := []bool{}
	for _, q := range queries {
		l, r, k := q[0], q[1], q[2]
		m := bits.OnesCount32(pre[r+1] ^ pre[l])
		ans = append(ans, (m/2 <= k))
	}
	return ans
}

func main() {
	s := "hunu"
	queries := [][]int{{1, 1, 1}, {2, 3, 0}, {3, 3, 1}, {0, 3, 2}, {1, 3, 3}, {2, 3, 1}, {3, 3, 1}, {0, 3, 0}, {1, 1, 1}, {2, 3, 0}, {3, 3, 1}, {0, 3, 1}, {1, 1, 1}}
	ans := canMakePaliQueries(s, queries)
	fmt.Println(ans)
}
