#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
有两个水壶，容量分别为 jug1Capacity 和 jug2Capacity 升。水的供应是无限的。
确定是否有可能使用这两个壶准确得到 targetCapacity 升。

如果可以得到 targetCapacity 升水，最后请用以上水壶中的一或两个来盛放取得的 targetCapacity 升水。

你可以：

装满任意一个水壶
清空任意一个水壶
从一个水壶向另外一个水壶倒水，直到装满或者倒空
输入: jug1Capacity = 3, jug2Capacity = 5, targetCapacity = 4
输出: true

方法一：爆搜 DFS + 栈模拟 避免递归太深
dfs(remain_x, remain_y)
dfs(x, remain_y); // 灌满 x
dfs(remain_x, y); // 灌满 y
dfs(0, remain_y); // 清空 x
dfs(remain_x, 0); // 清空 y
dfs(remain_x - min(remain_x, y - remain_y), remian_y + min(remain_x, y - remain_y)); // x->y
dfs(remain_x + min(remain_y, x - remain_x), remian_y - min(remain_y, x - remain_x)); // y->x

方法二：数学
https://leetcode.cn/problems/water-and-jug-problem/solutions/161010/shui-hu-wen-ti-by-leetcode-solution
 */
class Solution {
 public:
  bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
    if (jug1Capacity + jug2Capacity < targetCapacity) {
      return false;
    }
    if (jug1Capacity == 0 || jug2Capacity == 0) {
      return targetCapacity == 0 || jug1Capacity + jug2Capacity == targetCapacity;
    }
    return targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0;
  }
};
int main() {

  Solution test;
  return 0;
}
