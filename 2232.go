package main

import (
	"fmt"
	"strconv"
	"strings"
)

func minimizeResult(expression string) (str string) {
	mul := strings.Split(expression, "+")
	l, r := mul[0], mul[1]
	minn := 0x3f3f3f3f3f3f

	for i := 0; i < len(l); i++ {
		a := 1
		if i > 0 {
			a, _ = strconv.Atoi(l[:i])
		}
		b, _ := strconv.Atoi(l[i:])
		for j := 1; j < len(r)+1; j++ {
			c, _ := strconv.Atoi(r[:j])
			d := 1
			if j < len(r) {
				d, _ = strconv.Atoi(r[j:])
			}
			res := a * (b + c) * d
			if res < minn {
				minn = res
				str = fmt.Sprintf("%s(%s+%s)%s", l[:i], l[i:], r[:j], r[j:])
			}
		}

	}
	return
}

func main() {
	str := "99+999"
	res := minimizeResult(str)
	fmt.Printf("%s\n", res)
}
