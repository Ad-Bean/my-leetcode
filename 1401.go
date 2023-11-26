package main

import (
	"fmt"
)

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func checkOverlap(radius int, xCenter int, yCenter int, x1 int, y1 int, x2 int, y2 int) bool {
	dist := 0
	if xCenter < x1 || xCenter > x2 {
		dist += min((x1-xCenter)*(x1-xCenter), (x2-xCenter)*(x2-xCenter))
		fmt.Printf("%v\n", min((x1-xCenter)*(x1-xCenter), (x2-xCenter)*(x2-xCenter)))
	}
	if yCenter < y1 || yCenter > y2 {
		dist += min((y1-yCenter)*(y1-yCenter), (y2-yCenter)*(y2-yCenter))
		fmt.Printf("%v\n", min((y1-yCenter)*(y1-yCenter), (y2-yCenter)*(y2-yCenter)))
	}
	fmt.Printf("%v\n", dist)
	return dist <= radius*radius
}

//  x,y  = 1,0
// x1,y1 = 0,0
// x2,y2 = 2,2

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	res := checkOverlap(1, 1, 0, 0, 0, 2, 2)
	fmt.Printf("%v\n", res)
}
