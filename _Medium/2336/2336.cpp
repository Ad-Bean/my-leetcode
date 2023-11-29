
#include <bits/stdc++.h>
using namespace std;
/* 
初始化 1,2,3,4,5....
popSmallest 移除返回最小
addBack 如果不存在则添加

简单的想法：idx = 1，pop 不断递增，但 addBack 会添加之前的数

[ 1,  2,  3,  4,  5,  6....]
 idx
用 idx 表示当前可以弹出的最小值
如果假如的数字比 idx 指向的小，需要在 [0, idx) 中找更小的，可以用有序集合保存
*/
typedef long long ll;
class SmallestInfiniteSet {
  set<int> st;
  int idx = 1;

 public:
  SmallestInfiniteSet() {}

  int popSmallest() {
    if (!st.empty()) {
      int val = *st.begin();
      st.erase(val);
      return val;
    }
    return idx++;
  }

  void addBack(int num) {
    if (num < idx) {
      st.insert(num);
    }
  }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * 
 * 
 * 
 */
int main() {
  SmallestInfiniteSet* obj = new SmallestInfiniteSet();
  int param_1 = obj->popSmallest();
  obj->addBack(10);
  Solution test;
  return 0;
}