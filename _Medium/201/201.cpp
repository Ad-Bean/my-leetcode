#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你两个整数 left 和 right ，表示区间 [left, right] ，
返回此区间内所有数字 按位与 的结果（包含 left 、right 端点）。
0 <= left <= right <= 2^31 - 1

输入：left = 5, right = 7
输出：4
101
110
111
---
100


暴力：遍历区间内的所有数字，按位与，但数据量大，会超时
按位与的过程中，只要有一个 0 就是 0
将 left 和 right 对齐，找到最左侧的共同前缀，后面全是 0


方法一：位移
找到 left 和 right 的最左侧的共同前缀
不断右移，直到 left == right
 */
class Solution {
 public:
  int rangeBitwiseAnd(int left, int right) {
    int cnt = 0;
    while (left != right) {
      left >>= 1;
      right >>= 1;
      cnt++;
    }
    return left << cnt;
  }
};
int main() {

  Solution test;
  return 0;
}
