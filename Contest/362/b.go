package main

func isReachableAtTime(sx int, sy int, fx int, fy int, t int) bool {
	least := abs(fx-sx) + max(0, abs(fy-sy)-abs(fx-sx))
	if least == 0 && t == 1 {
		return false
	}
	if t < least {
		return false
	}
	return true
}

/*
fx - sx + max(0, fy-sy-(fx-sx))

1 2
1 2
1

1 4
1 3
1



*/
