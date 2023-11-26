package main

/*

s1 s2 二进制串，长度 n，给正整数 x

对 s1 操作任意次，反转 s1[i] s1[j] 代价为 x；或者对 i < n - 1，反转 s1[i] 和 s1[i+1]，代价为 1


返回使得 s1 s2 相等的最小操作代价之和

例：
s1 = "1100011000"
s2 = "0101001010"
x = 2

输出：
4

解释：
选择 i = 3 反转 s1[3] 和 s1[4] 得到 110 11 11000
选择 i = 4 反转 s1[4] 和 s1[5] 得到 1101 00 1000
选择 i = 0 j = 8 反转 s1[0] s1[8] 得到 0101001010

为什么不能贪心？数据较小 n <= 500，不一定都是反转最远的
1000001100000000001
0000000000000000000
1. 反转 第一段前后 第二段前后 ：x + x
2. 反转 最远前后，中间连续反转：x + 1
*/

/*

DP 就是暴力：
* On^2
从后往前，如果相等则不用反转，如果不相等则需要反转：
1. 采用方法 1，则前面有一个可以免费反转
2. 采用方法 2，则要知道之前是否反转

i 是下标，j 是免费反转次数，prev_rev 表示 i+1 是否反转
var dfs func(int, int, bool) int
dfs = func(i, j int, prev_rev bool) int {
	if i < 0 {
		if j > 0 || prev_rev {
			return -1
		}
	}
	if (!prev_rev) == (s1[i] == s2[i]) {
		// 前一位不反转且相等则不需要反转
		// 前一位  反转且不相等则需要反转
		return dfs(i-1, j, false)
	}
	res1 := dfs(i-1, j+1, false) + x
	res2 := dfs(i-1, j, true) + 1
	res := min(res1, res2)
	if j > 0 {
		res3 := dfs(i-1, j-1, false)
		res = min(res, res3)
	}
	return res
}
return dfs(len(s1)-1, 0, false)

*/

/*
* On
s1 = "1100011000", s2 = "0101001010", x = 2
p  [0,3,5,8]
第一种操作 dfs(i-1) + x/2
第二种操作 dfs(i-2) + p[i] - p[i-1]

var dfs func(int) int
dfs = func(i int) int {
	if i == -1 {
		return 0
	}
	res1 := dfs(i-1) + x
	res2 := 0
	if i > 0 {
		res2 = dfs(i-1) + (p[i]-p[i-1])*2 // 不断往前反转
	}
	return min(res1, res2)
}
return dfs(m-1) / 2

dfs 翻译成递推

* 特判，如果 s1 的 1 个数奇偶性和 s2 不一致，则无法交换
* 比如 s1: 111  s2: 011
*/
// func countOne(s string) (cnt int) {
// 	for _, c := range s {
// 		if c == '1' {
// 			cnt++
// 		}
// 	}
// 	return
// }

// if countOne(s1)%2 != countOne(s2)%2 {
// 	return -1
// }
func minOperations(s1 string, s2 string, x int) int {
	p := []int{}
	for i := range s1 {
		if s1[i] != s2[i] {
			p = append(p, i)
		}
	}
	m := len(p)
	if m == 0 {
		return 0
	}
	if m%2 == 1 {
		return -1
	}
	f := make([]int, m+1)
	f[0], f[1] = 0, x
	for i := 0; i < m; i++ {
		f[i+1] = min(f[i]+x, f[i-1]+(p[i]-p[i-1])*2)
	}
	return f[m] / 2
}
