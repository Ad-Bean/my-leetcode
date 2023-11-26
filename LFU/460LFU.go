package main

/*
https://leetcode.com/problems/lfu-cache/
最近最少使用
LFU: Least Frequently Used
一个键 map 通过 key 对应的 Node 节点，保存 key, value 和 frequency
一个双向链表 map 通过 frequency 对应相应的双向链表，存储这个频率下的所有节点，可能会退化到 LRU，头节点是最近使用，尾节点是最少使用

插入：
1. 如果存在，则在 fre_table 删掉之后更新到 fre+1 的双向链表中
2. 如果不存在，先判断 key_table 是否已满，满了则推出 min_fre 的尾节点；没满则直接加到 fre = 1 的双向链表的头节点

查询：
1. 存在则更新，在 fre_table 删掉之后更新到 fre+1 的双向链表中

*/

type Node struct {
	k, v, f    int
	prev, next *Node
}

type DNodeList struct {
	size                 int
	dummyHead, dummyTail *Node
}

func NewDNodeList() *DNodeList {
	dH, dT := &Node{-1, -1, 0, nil, nil}, &Node{-1, -1, 0, nil, nil}
	dH.next, dT.prev = dT, dH
	return &DNodeList{
		size:      0,
		dummyHead: dH,
		dummyTail: dT,
	}
}

func (this *DNodeList) removeNode(node *Node) {
	pre, nxt := node.prev, node.next
	pre.next = nxt
	nxt.prev = pre
	this.size -= 1
}

func (this *DNodeList) getHead() *Node {
	return this.dummyHead.next
}

func (this *DNodeList) getTail() *Node {
	return this.dummyTail.prev
}

func (this *DNodeList) addToHead(node *Node) {
	nxt := this.dummyHead.next
	node.prev = this.dummyHead
	this.dummyHead.next = node
	node.next = nxt
	nxt.prev = node
	this.size += 1
}

type LFUCache struct {
	minFre, capacity int
	key_table        map[int]*Node
	fre_table        map[int]*DNodeList
}

func Constructor(capacity int) LFUCache {
	return LFUCache{
		minFre:    0,
		capacity:  capacity,
		key_table: map[int]*Node{},
		fre_table: map[int]*DNodeList{},
	}
}

func (this *LFUCache) Get(key int) int {
	node, ok := this.key_table[key]
	if !ok {
		return -1
	}
	this.fre_table[node.f].removeNode(node)
	// 最小的 fre 被删掉了，更新到下一个 fre
	if this.fre_table[node.f].size == 0 {
		delete(this.fre_table, node.f)
		if this.minFre == node.f {
			this.minFre += 1
		}
	}
	_, ok = this.fre_table[node.f+1]
	if !ok {
		this.fre_table[node.f+1] = NewDNodeList()
	}
	this.fre_table[node.f+1].addToHead(&Node{key, node.v, node.f + 1, nil, nil})
	this.key_table[key] = this.fre_table[node.f+1].getHead()
	return node.v
}

func (this *LFUCache) Put(key int, value int) {
	_, ok := this.key_table[key]
	if ok {
		// 存在则更新：先删掉旧的频率，更新缓存的值
		node := this.key_table[key]
		this.fre_table[node.f].removeNode(node)
		if this.fre_table[node.f].size == 0 {
			delete(this.fre_table, node.f)
			if this.minFre == node.f {
				this.minFre += 1
			}
		}
		_, ok = this.fre_table[node.f+1]
		if !ok {
			this.fre_table[node.f+1] = NewDNodeList()
		}
		this.fre_table[node.f+1].addToHead(&Node{key, value, node.f + 1, nil, nil})
		this.key_table[key] = this.fre_table[node.f+1].getHead()
	} else {
		// 不存在插入：检查是否已满，满则删除
		if len(this.key_table) == this.capacity {
			// 最少使用
			node := this.fre_table[this.minFre].getTail()
			delete(this.key_table, node.k)
			this.fre_table[this.minFre].removeNode(node)
			if this.fre_table[this.minFre].size == 0 {
				delete(this.fre_table, this.minFre)
			}
		}
		_, ok = this.fre_table[1]
		if !ok {
			this.fre_table[1] = NewDNodeList()
		}
		this.fre_table[1].addToHead(&Node{key, value, 1, nil, nil})
		this.key_table[key] = this.fre_table[1].getHead()
		this.minFre = 1
	}
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
