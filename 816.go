package main

func ambiguousCoordinates(s string) (res []string) {
	getPos := func(x string) (pos []string) {
		if x[0] != '0' || x == "0" {
			pos = append(pos, x)
		}
		for p := 1; p < len(x); p++ {
			if p != 1 && x[0] == '0' || x[len(x)-1] == '0' {
				continue
			}
			pos = append(pos, x[:p]+"."+x[p:])
		}
		return
	}
	n := len(s) - 2
	s = s[1 : n+1]
	for l := 1; l < n; l++ {
		lt := getPos(s[:l])
		if len(lt) == 0 {
			continue
		}
		rt := getPos(s[l:])
		if len(rt) == 0 {
			continue
		}
		for _, i := range lt {
			for _, j := range rt {
				res = append(res, "("+i+", "+j+")")
			}
		}
	}
	return
}
