package main

func buddyStrings(s string, t string) bool {
	n, m := len(s), len(t)
	if n != m {
		return false
	}
	mp1, mp2 := make([]int, 26), make([]int, 26)
	dif := 0
	for i := range s {
		mp1[s[i]-'a']++
		mp2[t[i]-'a']++
		if s[i] != t[i] {
			dif++
		}
	}
	flag := false
	for i := range mp1 {
		if mp1[i] != mp2[i] {
			return false
		}
		if mp1[i] > 1 {
			flag = true
		}
	}
	return dif == 2 || (dif == 0 && flag)
}
