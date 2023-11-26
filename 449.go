package main

import (
	"strconv"
	"strings"
)

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type Codec struct{}

func Constructor() (_ Codec) { return }

// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {
	arr := []string{}
	var postOrder func(*TreeNode)
	postOrder = func(node *TreeNode) {
		if node == nil {
			return
		}
		postOrder(node.Left)
		postOrder(node.Right)
		arr = append(arr, strconv.Itoa(node.Val))
	}
	postOrder(root)
	return strings.Join(arr, " ")
}

// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {
	if data == "" {
		return nil
	}
	arr := strings.Split(data, " ")
	var construct func(int, int) *TreeNode
	construct = func(l, r int) *TreeNode {
		if len(arr) == 0 {
			return nil
		}
		val, _ := strconv.Atoi(arr[len(arr)-1])
		if val < l || val > r {
			return nil
		}
		arr = arr[:len(arr)-1]
		return &TreeNode{Val: val, Right: construct(val, r), Left: construct(l, val)}
	}
	return construct(-0x3f3f3f3f, 0x3f3f3f3f)
}

/**
 * Your Codec object will be instantiated and called as such:
 * ser := Constructor()
 * deser := Constructor()
 * tree := ser.serialize(root)
 * ans := deser.deserialize(tree)
 * return ans
 */

// 2, 1, 3

/*
   2
  / \
 1  3

inorder:   [1, 2, 3]
postorder: [1, 3, 2]




*/
