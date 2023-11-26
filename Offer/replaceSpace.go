package main

import (
	"fmt"
	"strings"
)

func main() {
	s := "leetcode leetcode sss"
	fmt.Printf("%s\n", replaceSpace(s))
}

// Go strings cannot be edited
func replaceSpace(s string) string {
	var res string
	strs := strings.Split(s, " ")
	for _, str := range strs {
		res += str
		res += "%20"
	}
	res = res[:len(res)-3]
	return res
}
