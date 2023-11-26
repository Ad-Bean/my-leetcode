package main

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

// 自下而上构建二叉树
// 选 arr 两个相邻 -> 新节点左右节点
// 新节点替代两个相邻元素
// 如果 arr 剩余元素 > 1，循环第一步，否则终止，为根节点
// 问题转化：
//  给定一个数组 arr，不断地合并相邻的数，合并代价为两个数的乘积，
// 合并之后的数为两个数的最大值，直到数组只剩一个数，求最小合并代价和。

// 套用单调栈算法（栈元素从底到顶是严格递减的）
func mctFromLeafValues(arr []int) int {
	res, stk := 0, []int{}
	for _, x := range arr {
		for len(stk) > 0 && stk[len(stk)-1] <= x {
			if len(stk) == 1 || stk[len(stk)-2] > x {
				res += stk[len(stk)-1] * x
			} else {
				res += stk[len(stk)-2] * stk[len(stk)-1]
			}
			stk = stk[:len(stk)-1]
		}
		stk = append(stk, x)
	}
	for len(stk) > 1 {
		res += stk[len(stk)-2] * stk[len(stk)-1]
		stk = stk[:len(stk)-1]
	}
	return res
}
