package main

func gcdOfStrings(str1 string, str2 string) string {
	var checker func(t, s string) bool
	checker = func(t, s string) bool {
		mul := len(s) / len(t)
		tt := ""
		for i := 1; i < mul; i++ {
			tt += t
		}
		return tt == s
	}
	n, m := len(str1), len(str2)
	for i := min(n, m); i >= 1; i-- {
		if n%i == 0 && m%i == 0 {
			tmp := str1[:i]
			if checker(tmp, str1) && checker(tmp, str2) {
				return tmp
			}
		}
	}
	return ""
}
