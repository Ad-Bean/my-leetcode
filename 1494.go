package main

import (
	"bits"
	"math"
)

func minNumberOfSemesters(n int, relations [][]int, k int) int {
	pre1 := make([]int, n)
	for _, r := range relations {
		pre1[r[1]-1] |= 1 << (r[0] - 1) // r[1] 的先修课程集合，下标改从 0 开始
	}

	u := 1<<n - 1 // 全集
	memo := make([]int, 1<<n)
	for i := range memo {
		memo[i] = -1 // -1 表示没有计算过
	}
	var dfs func(int) int
	dfs = func(i int) (res int) {
		if i == 0 { // 空集
			return
		}
		p := &memo[i]
		if *p != -1 { // 之前算过了
			return *p
		}
		defer func() { *p = res }() // 记忆化
		ci := u ^ i                 // i 的补集
		i1 := 0
		for j, p := range pre1 {
			if i>>j&1 > 0 && p|ci == ci { // p 在 i 的补集中
				i1 |= 1 << j
			}
		}
		if bits.OnesCount(uint(i1)) <= k { // 如果个数小于 k，则可以全部学习，不再枚举子集
			return dfs(i^i1) + 1
		}
		res = math.MaxInt
		// https://oi-wiki.org/math/binary-set/
		for j := i1; j > 0; j = (j - 1) & i1 { // 枚举 i1 的子集 j
			if bits.OnesCount(uint(j)) <= k {
				res = min(res, dfs(i^j)+1)
			}
		}
		return res
	}
	return dfs(u)
}
