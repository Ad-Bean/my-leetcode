package main

func pivotInteger(n int) int {
	sum := (1 + n) * n / 2
	cnt := 0
	for i := 1; i < n; i++ {
		cnt += i
		if cnt*2 == sum+i {
			return i
		}
	}
	return -1
}

// sum 36 36-21 = 15
