package main

import (
	"container/heap"
	"sort"
)

type Heap struct {
	sort.IntSlice
}

func (h *Heap) Len() int               { return len(h.IntSlice) }
func (h *Heap) Less(i int, j int) bool { return h.IntSlice[i] > h.IntSlice[j] }
func (h *Heap) Push(x any)             { h.IntSlice = append(h.IntSlice, x.(int)) }
func (h *Heap) Pop() any {
	v := h.IntSlice[len(h.IntSlice)-1]
	h.IntSlice = h.IntSlice[:len(h.IntSlice)-1]
	return v
}

// duration, lastday
func scheduleCourse(courses [][]int) int {
	sort.Slice(courses, func(i, j int) bool { return courses[i][1] < courses[j][1] })
	h := &Heap{}
	day := 0
	for _, c := range courses {
		duration := c[0]
		if day+duration <= c[1] {
			day += duration
			heap.Push(h, duration)
		} else if h.Len() > 0 && h.IntSlice[0] > duration {
			last := heap.Pop(h).(int)
			day = day - last + duration
			heap.Push(h, duration)
		}
	}
	return h.Len()
}
