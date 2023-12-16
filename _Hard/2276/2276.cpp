
#include <bits/stdc++.h>
using namespace std;
/* 
给你区间的 空 集，请你设计并实现满足要求的数据结构：

新增：添加一个区间到这个区间集合中。
统计：计算出现在 至少一个 区间中的整数个数。
实现 CountIntervals 类：

CountIntervals() 使用区间的空集初始化对象
void add(int left, int right) 添加区间 [left, right] 到区间集合之中。
int count() 返回出现在 至少一个 区间中的整数个数。
注意：区间 [left, right] 表示满足 left <= x <= right 的所有整数 x 。

方法一：平衡二叉搜索树（map 底层 红黑树）
map<int, int> mp;
平衡二叉树维护区间，两两不相交，按插入左端排序
插入新区间 [l,r]：找出所有与待插入区间有重合的区间，合并后插入
即找到最大的间隔 interval <= r，是可能与待插入间隔相交的最大的间隔，相交则合并

auto interval = mp.upper_bound(r); // 第一个大于 r 的区间左值
if (interval != mp.end()) { interval--; } // 合并到左边

while(interval != mp.end() && interval->first <= r && interval->second >= l) {
    l = min(l, interval->first);
    r = max(r, interval->second); // 相交则合并
    cnt = cnt - (interval->second - interval->second + 1);
    mp.erase(interval);
    interval = mp.upper_bound(r); // 找下一个相交
    if (interval != mp.begin()) {
        interval--;               // 合并到左边
    }
}

cnt += (r - l + 1);
mp[l] = r;

方法二：珂朵莉树

方法三：线段树 + 动态开点
 */

typedef long long ll;
typedef pair<int, int> pii;
class CountIntervals {
  map<int, int> mp;
  int cnt = 0;

 public:
  CountIntervals() {}

  void add(int l, int r) {
    auto interval = mp.upper_bound(r);  // 第一个大于 r 的区间左值
    if (interval != mp.begin()) {
      interval--;
    }  // 如果在两个区间中，合并到左边

    while (interval != mp.end() && interval->first <= r && l <= interval->second) {
      l = min(l, interval->first);
      r = max(r, interval->second);  // 相交则合并
      cnt -= (interval->second - interval->first + 1);
      mp.erase(interval);

      interval = mp.upper_bound(r);  // 找下一个相交
      if (interval != mp.begin()) {
        interval--;  // 合并到左边
      }
    }
    cnt += (r - l + 1);
    mp[l] = r;
  }

  int count() { return cnt; }
};
int main() {

  Solution test;
  return 0;
}