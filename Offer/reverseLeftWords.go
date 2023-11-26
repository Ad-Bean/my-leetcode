package main

func reverseLeftWords(s string, n int) string {
	// return s[n:] + s[:n]
	res := make([]byte, len(s))
	j := 0
	for i := n; i < len(s)+n; i++ {
		res[j] = s[i%len(s)]
		j++
	}
	return string(res)
}
