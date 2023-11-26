package main

/**
 * This is the MountainArray's API interface.
 * You should not implement it, or speculate about its implementation
 */

type MountainArray struct {
}

func (this *MountainArray) get(index int) (_ int) { return }
func (this *MountainArray) length() (_ int)       { return }

func findInMountainArray(target int, mountainArr *MountainArray) int {
	l, r := 0, mountainArr.length()-1
	for l < r {
		m := l + (r-l)/2
		if mountainArr.get(m) < mountainArr.get(m+1) {
			l = m + 1
		} else {
			r = m
		}
	}

	binarySearch := func(ll, rr int, key func(int) int) int {
		t := key(target)
		for ll <= rr {
			m := ll + (rr-ll)/2
			val := key(mountainArr.get(m))
			if val == t {
				return m
			} else if val < t {
				ll = m + 1
			} else {
				rr = m - 1
			}
		}
		return -1
	}
	idx := binarySearch(0, l, func(i int) int { return i })
	if idx == -1 {
		return binarySearch(l+1, mountainArr.length()-1, func(i int) int { return -i })
	}
	return idx
}
