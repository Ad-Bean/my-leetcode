package main

// Definition for a Node.
type Node struct {
	Val       int
	Neighbors []*Node
}

func cloneGraph(node *Node) *Node {
	vis := map[*Node]*Node{}
	var dfs func(*Node) *Node
	dfs = func(node *Node) *Node {
		if node == nil {
			return nil
		}

		if _, ok := vis[node]; ok {
			return vis[node]
		}
		cNode := &Node{node.Val, []*Node{}}
		vis[node] = cNode
		for _, neighbor := range node.Neighbors {
			cNode.Neighbors = append(cNode.Neighbors, dfs(neighbor))
		}
		return cNode
	}
	return dfs(node)
}
