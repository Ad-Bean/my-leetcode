package main

func findTheDifference(s string, t string) byte {
	mp1, mp2 := [26]int{}, [26]int{}
	for _, c := range s {
		mp1[int(c-'a')]++
	}
	for _, c := range t {
		mp2[int(c-'a')]++
	}

	for _, c := range t {
		if mp2[int(c-'a')]-mp1[int(c-'a')] == 1 {
			return byte(c)
		}
	}
	return ' '
}
