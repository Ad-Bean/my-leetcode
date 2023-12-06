package main

import "fmt"

// 快速幂 递归
// x^64 -> x^32 * x^32 ...
// x^65 -> x * x^64
func myPow(x float64, n int) float64 {
	var quick func(float64, int) float64
	quick = func(f float64, i int) float64 {
		// fmt.Printf("%f %d\n", f, i)
		if i == 0 {
			return 1
		}
		y := quick(f, i/2)
		if i%2 == 0 {
			// 需要提前保存否则超时
			return y * y
		}
		return y * y * f
	}

	if n >= 0 {
		return quick(x, n)
	}
	return 1.0 / quick(x, -n)
}

// x^n -> 对 n 二进制拆分
// x^77
// 1001101
// 64+8+4+1 == 77
func myPow2(x float64, n int) float64 {
	var quick func(float64, int) float64
	quick = func(f float64, i int) float64 {
		ans, x_c := 1.0, f
		for i > 0 {
			if i%2 == 1 {
				ans *= x_c
			}
			x_c *= x_c
			i /= 2
		}
		return ans
	}

	if n >= 0 {
		return quick(x, n)
	}
	return 1.0 / quick(x, -n)
}

func main() {
	x := 2.0
	n := 10
	res := myPow2(x, n)
	fmt.Printf("%f", res)
}
