package main

// func max(a, b int) int { if a>b {return a}; return b}
func minimumJumps(forbidden []int, a int, b int, x int) int {
	lower, maxVal := 0, 0
	for _, val := range forbidden {
		maxVal = max(maxVal, val)
	}
	upper := max(maxVal+a, x) + b //?
	q := [][3]int{[3]int{0, 1, 0}}
	vis, forbiddenSet := make(map[int]bool), make(map[int]bool)
	vis[0] = true
	for _, forb := range forbidden {
		forbiddenSet[forb] = true
	}

	for len(q) > 0 {
		pos, dir, step := q[0][0], q[0][1], q[0][2]
		q = q[1:]
		if pos == x {
			return step
		}
		nxP, nxD := pos+a, 1
		_, ok1 := vis[nxP*nxD]
		_, ok2 := forbiddenSet[nxP]
		if lower <= nxP && nxP <= upper && !ok1 && !ok2 {
			vis[nxP*nxD] = true
			q = append(q, [3]int{nxP, nxD, step + 1})
		}
		if dir == 1 {
			nxP, nxD := pos-b, -1
			_, ok1 := vis[nxP*nxD]
			_, ok2 := forbiddenSet[nxP]
			if lower <= nxP && nxP <= upper && !ok1 && !ok2 {
				vis[nxP*nxD] = true
				q = append(q, [3]int{nxP, nxD, step + 1})
			}
		}
	}
	return -1
}
