package main

func computeArea(ax1 int, ay1 int, ax2 int, ay2 int, bx1 int, by1 int, bx2 int, by2 int) int {
	w := min(ax2, bx2) - max(ax1, bx1)
	h := min(by2, ay2) - max(ay1, by1)
	area := max(0, w) * max(0, h)
	return (ax2-ax1)*(ay2-ay1) + (bx2-bx1)*(by2-by1) - area
}
