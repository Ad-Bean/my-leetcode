package main

import "strings"

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func printBin(num float64) string {
	str := &strings.Builder{}
	str.WriteString("0.")
	for str.Len() <= 32 && num != 0 {
		num *= 2
		digit := byte(num)
		str.WriteByte('0' + digit)
		num -= float64(digit)
	}
	if str.Len() <= 32 {
		return str.String()
	}
	return "ERROR"
}
