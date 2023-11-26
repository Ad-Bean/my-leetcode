package main

func minimumSwap(s1 string, s2 string) int {
	xy, yx := 0, 0
	n := len(s1)
	for i := 0; i < n; i++ {
		a, b := s1[i], s2[i]
		if a == 'x' && b == 'y' {
			xy++
		}
		if a == 'y' && b == 'x' {
			yx++
		}
	}
	if (xy+yx)%2 == 1 {
		return -1
	}
	return xy/2 + yx/2 + xy%2 + yx%2
}
