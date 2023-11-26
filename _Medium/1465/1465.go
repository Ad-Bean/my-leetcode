package main

import "sort"

func maxArea(h int, w int, horizontalCuts []int, verticalCuts []int) int {
	const mod = 1e9 + 7
	sort.Ints(horizontalCuts)
	sort.Ints(verticalCuts)
	lenH, lenW := len(horizontalCuts), len(verticalCuts)
	maxH := max(horizontalCuts[0], h-horizontalCuts[lenH-1])
	for i := 1; i < lenH; i++ {
		maxH = max(maxH, horizontalCuts[i]-horizontalCuts[i-1])
	}
	maxW := max(verticalCuts[0], h-verticalCuts[lenW-1])
	for i := 1; i < lenW; i++ {
		maxW = max(maxW, verticalCuts[i]-verticalCuts[i-1])
	}

	return maxH * maxW % mod
}
