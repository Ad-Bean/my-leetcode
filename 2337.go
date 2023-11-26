package main

func canChange(start string, target string) bool {
	l, r, n := 0, 0, len(start)
	for l < n && r < n {
		for l < n && start[l] == '_' {
			l++
		}
		for r < n && target[r] == '_' {
			r++
		}
		if l < n && r < n {
			if start[l] != target[r] {
				return false
			}
			// c := start[l]
			// if c == 'L' && l < r || c == 'R' && l > r {
			// 	return false
			// }
			l++
			r++
		}
	}
	for l < n {
		if start[l] != '_' {
			return false
		}
		l++
	}
	for r < n {
		if target[r] != '_' {
			return false
		}
		r++
	}
	return true
}

func main() {
	s, t := "_R", "R_"
	ans := canChange(s, t)
}
