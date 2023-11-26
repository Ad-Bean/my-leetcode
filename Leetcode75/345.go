package main

func reverseVowels(s string) string {
	mp := map[byte]bool{
		'a': true,
		'e': true,
		'i': true,
		'o': true,
		'u': true,
		'A': true,
		'E': true,
		'I': true,
		'O': true,
		'U': true,
	}
	tmp := []byte(s)
	l, r, n := 0, len(s)-1, len(s)
	for l < r {
		for l < n && !mp[s[l]] {
			l++
		}
		for r > 0 && !mp[s[r]] {
			r--
		}
		if l < r {
			tmp[l], tmp[r] = tmp[r], tmp[l]
			l++
			r--
		}
	}
	return string(tmp)
}
