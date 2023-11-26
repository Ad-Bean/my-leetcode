package main

import "container/list"

const base = 114519

type MyHashSet struct {
	data []list.List
}

func Constructor() MyHashSet {
	return MyHashSet{make([]list.List, base)}
}

func (this *MyHashSet) hash(k int) int {
	return k % base
}

func (this *MyHashSet) Add(k int) {
	if !this.Contains(k) {
		h := this.hash(k)
		this.data[h].PushBack(k)
	}
}

func (this *MyHashSet) Remove(k int) {
	h := this.hash(k)
	for e := this.data[h].Front(); e != nil; e = e.Next() {
		if e.Value.(int) == k {
			this.data[h].Remove(e)
		}
	}
}

func (this *MyHashSet) Contains(k int) bool {
	h := this.hash(k)
	for e := this.data[h].Front(); e != nil; e = e.Next() {
		if e.Value.(int) == k {
			return true
		}
	}
	return false
}
