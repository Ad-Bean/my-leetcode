package main

/*
1 2 3 4
但周期是 1 2 3 4 3 2
*/
func passThePillow(n int, time int) (ans int) {
	a := time % (2 * (n - 1))
	if a < n {
		return a + 1
	}
	return n - (a - n) - 1
}
