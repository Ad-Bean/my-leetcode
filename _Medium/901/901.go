package main

/*
小于等于今天价格的最大连续日数


最小最大，所以是单调栈

100 80 60 70 60 75 85

100

100 80

100 80 60

100 80 70[2]

100 80 70[2] 60

100 80 75[4]

100 85[4+1+1]

1 1 1 2 1 4 6
*/
type StockSpanner struct {
	stk [][2]int
}

func Constructor() StockSpanner {
	return StockSpanner{[][2]int{}}
}

func (this *StockSpanner) Next(price int) int {
	cnt := 1
	for len(this.stk) > 0 && price >= this.stk[len(this.stk)-1][1] {
		cnt += this.stk[len(this.stk)-1][0]
		this.stk = this.stk[:len(this.stk)-1]
	}
	this.stk = append(this.stk, [2]int{cnt, price})
	return
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Next(price);
 */
