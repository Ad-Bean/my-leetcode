package main

/*
https://leetcode.cn/problems/lru-cache/description/
LRU: 双向链表 + 哈希 HashMap

因为 Put Get 都是 O1
所以头部的都是最近使用的，尾部都是最久未使用
哈希用于映射键值到双向链表位置

两个哨兵记录界限，就不需要检查相邻节点是否存在
*/

type DLinkedNode struct {
	k, v       int
	prev, next *DLinkedNode
}

type LRUCache struct {
	size, capacity int
	cache          map[int]*DLinkedNode
	head, tail     *DLinkedNode
}

func Constructor(capacity int) LRUCache {
	dummy1, dummy2 := &DLinkedNode{0, 0, nil, nil}, &DLinkedNode{0, 0, nil, nil}
	dummy1.next, dummy2.prev = dummy2, dummy1
	return LRUCache{
		size:     0,
		capacity: capacity,
		cache:    map[int]*DLinkedNode{},
		head:     dummy1,
		tail:     dummy2,
	}
}

func (this *LRUCache) Get(key int) int {
	node, ok := this.cache[key]
	if !ok {
		return -1
	}
	this.MoveToHead(node)
	return node.v
}

func (this *LRUCache) Put(key int, value int) {
	node, ok := this.cache[key]
	if ok {
		node.v = value
		this.MoveToHead(node)
	} else {
		newNode := &DLinkedNode{key, value, nil, nil}
		this.cache[key] = newNode
		this.addToHead(newNode)
		this.size++
		if this.size > this.capacity {
			node := this.removeTail()
			delete(this.cache, node.k)
			this.size--
		}
	}
}

func (this *LRUCache) removeNode(node *DLinkedNode) {
	node.next.prev = node.prev
	node.prev.next = node.next
}

func (this *LRUCache) addToHead(node *DLinkedNode) {
	node.prev = this.head
	node.next = this.head.next
	this.head.next.prev = node
	this.head.next = node
}

func (this *LRUCache) MoveToHead(node *DLinkedNode) {
	this.removeNode(node)
	this.addToHead(node)
}

func (this *LRUCache) removeTail() *DLinkedNode {
	node := this.tail.prev
	this.removeNode(node)
	return node
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
