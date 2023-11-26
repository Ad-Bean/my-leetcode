package main

func numberOfCuts(n int) int {
	if n == 1 {
		return 0
	}
	if n&1 == 1 {
		return n
	} else {
		return n / 2
	}
}

/*
1: 0
	2: 1
3: 3
	4: 2
5: 5
	6: 3
7: 7
	8: 4
*/
