package main

import (
	"sort"
)

/*
a,b,c,d,e

对 a: ... = a^3 + a^2(0) = a^3
对 b: ... = b^3 + b^2(a*2^0) = b^3 + b^2
对 c: ... = c^3 + c^2(a*2^1 + b*2^0)
...
对 d: d^3 + d^2*a*2^2 + d^2*b*2^1 + d^2*c*2^0 = d^3 + d^2*(a*2^2+b*2^1+c*2^0) = d^3+d^2*s = d^2 * (d + s)
对 e: e^3 + e^2*a*2^3 + e^2*b*2^2 + e^2*c*2^1 + e^2*d*2^0 = e^3 + e^2*(a*2^3+b*2^2+c*2^1+d*2^0)


num^2 * (num + prev)
prev = (num+ prev * 2)

*/

func sumOfPower(nums []int) (ans int) {
	const mod = 1e9 + 7
	sort.Ints(nums)
	s := 0
	for _, x := range nums {
		ans = (ans + x*x%mod*(x+s)) % mod
		s = (s*2 + x) % mod
	}
	return
}
