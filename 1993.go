package main

type LockingTree struct {
	parent, lock []int
	children     [][]int
}

func Constructor(parent []int) LockingTree {
	n := len(parent)
	lock := make([]int, n)
	children := make([][]int, n)
	for i := range lock {
		lock[i] = -1
		p := parent[i]
		if p != -1 {
			children[p] = append(children[p], i)
		}
	}
	return LockingTree{
		parent:   parent,
		lock:     lock,
		children: children,
	}
}

func (this *LockingTree) Lock(num int, user int) bool {
	if this.lock[num] == -1 {
		this.lock[num] = user
		return true
	}
	return false
}

func (this *LockingTree) Unlock(num int, user int) bool {
	if this.lock[num] == user {
		this.lock[num] = -1
		return true
	}
	return false
}

// 给所有子孙节点解锁，给该节点上锁：当前节点未上锁，至少有一个上锁子孙（任意用户），该节点没有上锁祖先
func (this *LockingTree) Upgrade(num int, user int) bool {
	if this.lock[num] == -1 && !this.hasLockAncestor(num) && this.checkAndUnlockDescendant(num) {
		this.lock[num] = user
		return true
	}
	return false
}

func (this *LockingTree) hasLockAncestor(num int) bool {
	num = this.parent[num]
	for num != -1 {
		if this.lock[num] != -1 {
			return true
		}
		num = this.parent[num]
	}
	return false
}

func (this *LockingTree) checkAndUnlockDescendant(num int) bool {
	flag := false             // 没有上锁子孙
	if this.lock[num] != -1 { // 有上锁子孙
		flag = true
	}
	this.lock[num] = -1
	for _, child := range this.children[num] {
		if this.checkAndUnlockDescendant(child) {
			flag = true
		}
	}
	return flag
}

/**
 * Your LockingTree object will be instantiated and called as such:
 * obj := Constructor(parent);
 * param_1 := obj.Lock(num,user);
 * param_2 := obj.Unlock(num,user);
 * param_3 := obj.Upgrade(num,user);
 */
