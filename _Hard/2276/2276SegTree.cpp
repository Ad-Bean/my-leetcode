#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
一：基础线段树（单点修改+区间查询）：

vector<int> sum (4 * n)

大小：下标从 1 开始 
4N （空间浪费）
2 << N.bit_length() （python 二进制长度 * 2）

修改：
o 当前结点下标，根节点 1，add(1,1,n,idx, val) 
void add(int o, int l, int r, int idx, int val) {
    if (l == r) { // 叶子 l == idx
        sum[o] += val;
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid) {
        add(o * 2, l, mid, idx, val);
    } else {
        add(o * 2 + 1, mid + 1, r, idx, val);
    }
    sum[o] = sum[o * 2] + sum[o * 2 + 1]
}

区间查询：
o 当前下标，查询 [L, R]
int query(int o, int l, int r, int L, int R) {
    if (L <= l && r <= R) {return sum[o];} // 查询区间 L lr R，包含当前区间 lr
    int sum = 0;
    int mid = (l + r) / 2;
    if (L <= mid) {
        sum += query(o * 2, l, mid, L, R);
    } 
    if (R > mid) {
        sum += query(o * 2 + 1, mid + 1, r, L, R);
    }
    return sum;
}

懒更新、延迟更新：
当查询区间包含当前区间的时候，停止更新
子区间：下次再更新？
lazy tag: 用一个数组维护每个区间需要更新的值
如果为 0 则不需要更新，否则更新在这个区间停止，不继续递归更新子区间了
后面的更新如果破坏 lazy tag，该区间就需要递归更新了

vector<int> tag(4 * n)

二：动态开点线段树（lazy，带区间更新）
void build(int o, int l, int r) {
    if (l == r) {
        return;
    }
    int m = (l + r) /2;
    build(o * 2, l, mid);
    build(o * 2 + 1, mid + 1, r);
    maintain(o);
}

void update(int o, int l, int r, int L, int R, int add) {
    if (L <= l && r <= R) {
        tag[o] += add;  // 不再继续递归更新
        return;  // L l r R 当前区间被查询区间包含
    }

    if (tag[o] != 0) { // 需要递归更新，传递 tag[o]
        tag[o*2] += tag[o];
        tag[o*2 + 1] += tag[o];
        tag[o] = 0;
    }
    int m = (l + r) / 2; 
    if (L <= m) {
        build(o * 2, l, mid, L,R, add);
    }
    if (R > m) {
        build(o * 2 + 1, mid + 1, r, L,R, add);
    }
    maintain
}


void maintain(int o) {
    sum[o] = sum[o * 2] + sum[o * 2 + 1] 
}

 */
class CountIntervals {
  int l, r;
  int cnt = 0;
  CountIntervals *left = nullptr, *right = nullptr;

 public:
  CountIntervals() : l(1), r(1e9) {}
  CountIntervals(int l, int r) : l(l), r(r) {}

  void add(int L, int R) {
    if (cnt == r - l + 1) {  // 已经完全覆盖
      return;
    }
    // 待添加区间 [L lr R] 覆盖当前区间，不再继续递归
    if (L <= l && r <= R) {
      cnt = r - l + 1;
      return;
    }
    int mid = l + (r - l) / 2;
    if (left == nullptr) {
      left = new CountIntervals(l, mid);  // 动态开点
    }
    if (right == nullptr) {
      right = new CountIntervals(mid + 1, r);  // 动态开点
    }
    if (L <= mid) {
      left->add(L, R);
    }
    if (R > mid) {
      right->add(L, R);
    }
    cnt = left->cnt + right->cnt;
  }

  int count() { return cnt; }
};

int main() {

  Solution test;
  return 0;
}

/* 
[1,                                   10]
[1,                                   5]  [6,                                10]
[1,                     3]  [4,      5]   [6,                  8]  [9,       10]
[1,      2]   [2,       3]  [4,4] [5,5]   [6,       7][8,      8]  [9,9] [10,10]
[1,1] [2,2]   [2,2] [3,3]                 [6,6]  [7,7]


查询 
LR [4,8]
lr [1,10]
mid = 5
L<=mid 查 [1,5] 
R>mid 查 [6,10]

lr [1,5]
LR [4,8]
mid = 3
L <= mid
R > mid 查 [3,5]，此时 LR[4,8] 包含 lr[3,5]，直接返回 [3,5] 的区间值即可

lr [6,10]
LR [4, 8]
mid = 8
L <= mid 查 [6,8]，此时 LR[4,8] 包含 [6,8]，直接返回 [6,8] 的区间值即可
R > mid

*/