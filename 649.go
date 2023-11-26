package main

func predictPartyVictory(senate string) string {
	r, d := []int{}, []int{}
	for i, sen := range senate {
		if sen == 'R' {
			r = append(r, i)
		} else {
			d = append(d, i)
		}
	}

	for len(r) > 0 && len(d) > 0 {
		// if radiant comes first, it can survive in the next round
		if r[0] < d[0] {
			r = append(r, r[0]+len(senate))
		} else {
			d = append(d, d[0]+len(senate))
		}
		// pop queue front until one of them is empty
		r = r[1:]
		d = d[1:]
	}
	if len(r) > 0 {
		return "Radiant"
	}
	return "Dire"
}
