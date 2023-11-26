package main

import "container/list"

const base = 114519

type Entry struct {
	k, v int
}

type MyHashMap struct {
	data []list.List
}

func Constructor() MyHashMap {
	return MyHashMap{make([]list.List, base)}
}

func (this *MyHashMap) hash(k int) int {
	return k % base
}

func (this *MyHashMap) Put(k int, v int) {
	h := this.hash(k)
	for e := this.data[h].Front(); e != nil; e = e.Next() {
		if et := e.Value.(Entry); et.k == k {
			e.Value = Entry{k, v}
			return
		}
	}
	this.data[h].PushBack(Entry{k, v})
}

func (this *MyHashMap) Get(k int) int {
	h := this.hash(k)
	for e := this.data[h].Front(); e != nil; e = e.Next() {
		if et := e.Value.(Entry); et.k == k {
			return et.v
		}
	}
	return -1
}

func (this *MyHashMap) Remove(k int) {
	h := this.hash(k)
	for e := this.data[h].Front(); e != nil; e = e.Next() {
		if et := e.Value.(Entry); et.k == k {
			this.data[h].Remove(e)
		}
	}
}
