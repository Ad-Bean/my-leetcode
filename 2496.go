package main

import (
	"strconv"
)

func maximumValue(strs []string) (res int) {
	for _, str := range strs {
		flag := false
		for _, c := range str {
			if c >= 'a' && c <= 'z' {
				res = max(res, len(str))
				flag = true
				break
			}
		}
		if !flag {
			num, _ := strconv.Atoi(str)
			res = max(res, num)
		}
	}
	return
}
