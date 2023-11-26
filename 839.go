package main

type UnionFind struct {
	cnt    int
	fa, sz []int
}

func NewUnionFind(n int) *UnionFind {
	fa, sz := make([]int, n), make([]int, n)
	for i := range fa {
		fa[i], sz[i] = i, i
	}
	return &UnionFind{
		cnt: n,
		fa:  fa,
		sz:  sz,
	}
}

func (uf *UnionFind) find(x int) int {
	if uf.fa[x] != x {
		uf.fa[x] = uf.find(uf.fa[x])
	}
	return uf.fa[x]
}

func (uf *UnionFind) union(x, y int) {
	fa_x, fa_y := uf.find(x), uf.find(y)
	if fa_x == fa_y {
		return
	}
	if uf.sz[fa_x] < uf.sz[fa_y] {
		fa_x, fa_y = fa_y, fa_x
	}
	uf.sz[fa_x] += uf.sz[fa_y]
	uf.fa[fa_y] = fa_x
	uf.cnt -= 1
}

func (uf *UnionFind) isSameUnion(x, y int) bool {
	return uf.find(x) == uf.find(y)
}

func isSimilar(x, y string) bool {
	dif := 0
	for i := range x {
		if x[i] != y[i] {
			dif++
			if dif > 2 {
				return false
			}
		}
	}
	return true
}

func numSimilarGroups(strs []string) int {
	n := len(strs)
	u := NewUnionFind(n)
	for i, str := range strs {
		for j := i + 1; j < n; j++ {
			if !u.isSameUnion(i, j) && isSimilar(str, strs[j]) {
				u.union(i, j)
			}
		}
	}
	return u.cnt
}
