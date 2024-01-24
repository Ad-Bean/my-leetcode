package main

import "strings"

func fullJustify(words []string, maxWidth int) (ans []string) {

	r, n := 0, len(words)
	for {
		l := r
		sum := 0
		for r < n && sum+len(words[r])+r-l <= maxWidth {
			sum += len(words[r])
			r++
		}
		if r == n {
			s := strings.Join(words[l:], " ")
			ans = append(ans, s+strings.Repeat(" ", maxWidth-len(s)))
			return
		}

		num := r - l
		space := maxWidth - sum
		if num == 1 {
			ans = append(ans, words[l]+strings.Repeat(" ", space))
			continue
		}
		avg := space / (num - 1)
		extra := space % (num - 1)
		s1 := strings.Join(words[l:l+extra+1], strings.Repeat(" ", avg+1))
		s2 := strings.Join(words[l+extra+1:r], strings.Repeat(" ", avg))
		ans = append(ans, s1+strings.Repeat(" ", avg)+s2)
	}
}
