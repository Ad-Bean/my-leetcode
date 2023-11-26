package main

import (
	"strconv"
)

func countSeniors(details []string) (sum int) {
	for _, detail := range details {
		age := detail[11:13]
		ageNum, _ := strconv.Atoi(age)
		if ageNum > 60 {
			sum++
		}
	}
	return
}
