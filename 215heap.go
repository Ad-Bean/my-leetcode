package main

import (
	"math/rand"
	"time"
)

// O(n): paritition selection sort
func findKthLargest(nums []int, k int) int {
	rand.Seed(time.Now().UnixNano())
	return quickSelect(nums, 0, len(nums)-1, len(nums)-k)
}

func quickSelect(a []int, l, r, index int) int {
	q := randomPartition(a, l, r)
	if q == index {
		return a[q]
	} else if q < index {
		return quickSelect(a, q+1, r, index)
	}
	return quickSelect(a, l, q-1, index)
}

func randomPartition(a []int, l, r int) int {
	i := rand.Int()%(r-l+1) + l
	a[i], a[r] = a[r], a[i]
	return partition(a, l, r)
}

func partition(a []int, l, r int) int {
	x := a[r]
	i := l - 1
	for j := l; j < r; j++ {
		if a[j] <= x {
			i++
			a[i], a[j] = a[j], a[i]
		}
	}
	a[i+1], a[r] = a[r], a[i+1]
	return i + 1
}

// O(nlogn): heap sort
// func findKthLargest(nums []int, k int) int {
// 	heapSize := len(nums)
// 	buildMaxHeap(nums, heapSize)
// 	for i := len(nums) - 1; i >= len(nums)-k+1; i-- {
// 		nums[0], nums[i] = nums[i], nums[0]
// 		heapSize--
// 		maxHeapify(nums, 0, heapSize)
// 	}
// 	return nums[0]
// }

// https://leetcode.cn/problems/kth-largest-element-in-an-array/solutions/307351/shu-zu-zhong-de-di-kge-zui-da-yuan-su-by-leetcode-/
// 最大堆：
// 完全二叉树，从 0 开始，左儿子 2 * i + 1，右儿子 2 * i + 2

// 建堆：
// 从第一个非叶节点 sz / 2 (最后一个叶子为 sz-1, 除 2 得到其父节点) 开始调整

// 左儿子 a[i*2 + 1]
// 右儿子 a[i*2 + 2]
// 两两比较，largest 记录最大的下标
// 交换后由于当前 a[largest] 为根的子树不一定是大顶堆，继续 maxHeapify(a, largest, heapSize) 沉底

// Pop 操作： swap(nums[0], nums[len - 1]), heapSize--, maxHeapify(nums, 0, heapSize) 渗透

func buildMaxHeap(a []int, heapSize int) {
	for i := heapSize / 2; i >= 0; i-- {
		maxHeapify(a, i, heapSize)
	}
}

func maxHeapify(a []int, i, heapSize int) {
	l, r := i*2+1, i*2+2
	largest := i
	if l < heapSize && a[l] > a[largest] {
		largest = l
	}
	if r < heapSize && a[r] > a[largest] {
		largest = r
	}
	if largest != i {
		a[i], a[largest] = a[largest], a[i]
		maxHeapify(a, largest, heapSize)
	}
}

/*
       3
      / \
->   6  5
    /\  /\
-> 2 2 4 3
  / \
 5  1

交换 6 和 2 之后，i = 1, largest = 2 * i + 1 = 3
largest 为根的子树不满足大根堆定义，继续沉底

*/
