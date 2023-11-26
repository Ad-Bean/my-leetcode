package main

import (
	"fmt"
	"sort"
)

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

type Node struct {
	x   int
	cnt int
}

func NewNode(x, cnt int) *Node {
	return &Node{x, cnt}
}

func (n *Node) Add(that *Node) *Node {
	if n.x == that.x {
		n.cnt += that.cnt
	} else if n.cnt >= that.cnt {
		n.cnt -= that.cnt
	} else {
		n.x = that.x
		n.cnt = that.cnt - n.cnt
	}
	return n
}

type MajorityChecker struct {
	n   int
	arr []int
	loc map[int][]int
	seg []*Node
}

func Constructor(arr []int) *MajorityChecker {
	mc := new(MajorityChecker)
	mc.n = len(arr)
	mc.arr = make([]int, mc.n)
	copy(mc.arr, arr)

	mc.loc = make(map[int][]int)
	for i := 0; i < mc.n; i++ {
		mc.loc[mc.arr[i]] = append(mc.loc[mc.arr[i]], i)
	}

	mc.seg = make([]*Node, mc.n*4)
	mc.segBuild(0, 0, mc.n-1)

	return mc
}

func (mc *MajorityChecker) Query(left, right, threshold int) int {
	ans := NewNode(0, 0)
	mc.segQuery(0, 0, mc.n-1, left, right, ans)
	pos := mc.loc[ans.x]
	occ := sort.Search(len(pos), func(i int) bool { return pos[i] > right }) - sort.Search(len(pos), func(i int) bool { return pos[i] >= left })
	if occ >= threshold {
		return ans.x
	}
	return -1
}

func (mc *MajorityChecker) segBuild(id, l, r int) *Node {
	node := NewNode(0, 0)
	if l == r {
		node.x = mc.arr[l]
		node.cnt = 1
	} else {
		mid := (l + r) / 2
		left := mc.segBuild(id*2+1, l, mid)
		right := mc.segBuild(id*2+2, mid+1, r)
		node.Add(left).Add(right)
	}
	mc.seg[id] = node
	return node
}

func (mc *MajorityChecker) segQuery(id, l, r, ql, qr int, ans *Node) {
	if l > qr || r < ql {
		return
	}
	if ql <= l && r <= qr {
		ans.Add(mc.seg[id])
		return
	}

	mid := (l + r) / 2
	mc.segQuery(id*2+1, l, mid, ql, qr, ans)
	mc.segQuery(id*2+2, mid+1, r, ql, qr, ans)
}

func main() {
	arr := []int{1, 1, 2, 2, 1, 1}
	mc := Constructor(arr)
	fmt.Println(mc.Query(0, 5, 4)) // output: 1
}

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * obj := Constructor(arr);
 * param_1 := obj.Query(left,right,threshold);
 */
