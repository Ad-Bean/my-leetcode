package main

/*
计算 [1, n] 中能被 3 5 7 整数之和


n = 7
1 2 3 4 5 6 7
n/3=2, 1*3 + 2*3 = 9 => (1 + 2) * 2 * 3 / 2 = 9
n/5=1  1*5
n/7=1  1*7
*/

func sumOfMultiples(n int) (sum int) {
	getSum := func(d int) int {
		k := n / d
		return k * (k + 1) * d / 2
	}

	return getSum(3) + getSum(5) + getSum(7) - getSum(3*5) - getSum(5*7) - getSum(3*7) + getSum(5*7*3)
}
