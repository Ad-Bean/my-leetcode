package main

import (
	"fmt"
	"sort"
)

func minProcessingTime(processorTime []int, tasks []int) (ans int) {
	n := len(processorTime)
	// max := func(a,b int) int {if a > b {return a}; return b}
	sort.Ints(processorTime)
	sort.Slice(tasks, func(i, j int) bool { return tasks[i] > tasks[j] })
	for i := 0; i < n; i++ {
		curtime := processorTime[i]
		for j := i * 4; j < i*4+4; j++ {
			curtime = max(curtime, tasks[j]+processorTime[i])
		}
		ans = max(ans, curtime)
	}
	return
}

func main() {
	p := []int{8, 10}
	t := []int{2, 2, 3, 1, 8, 7, 4, 5}
	fmt.Printf("%v\n", minProcessingTime(p, t))
}
