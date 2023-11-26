package main

// Definition for a Node.
type Node struct {
	Val    int
	Next   *Node
	Random *Node
}

// var mp map[*Node]*Node

// func deepCopy(node *Node) *Node {
// 	if node == nil {
// 		return nil
// 	}
// 	if n, has := mp[node]; has {
// 		return n
// 	}
// 	clone := &Node{Val: node.Val, Next: node}
// 	mp[node] = clone
// 	clone.Next = deepCopy(node.Next)
// 	clone.Random = deepCopy(node.Random)
// 	return clone
// }

// func copyRandomList(head *Node) *Node {
// 	if head == nil {
// 		return nil
// 	}
// 	mp = map[*Node]*Node{}
// 	return deepCopy(head)
// }

func copyRandomList(head *Node) *Node {
	if head == nil {
		return nil
	}
	for node := head; node != nil; node = node.Next.Next {
		node.Next = &Node{Val: node.Val, Next: node.Next}
	}
	for node := head; node != nil; node = node.Next.Next {
		if node.Random != nil {
			node.Next.Random = node.Random.Next
		}
	}

	newHead := head.Next
	for node := head; node != nil; node = node.Next {
		newNode := node.Next
		node.Next = node.Next.Next
		if newNode.Next != nil {
			newNode.Next = newNode.Next.Next
		}
	}
	return newHead
}

func main() {
}
