#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个下标从 0 开始、大小为 m x n 的二进制矩阵 matrix ；另给你一个整数 numSelect，表示你必须从 matrix 中选择的 不同 列的数量。

如果一行中所有的 1 都被你选中的列所覆盖，则认为这一行被 覆盖 了。

形式上，假设 s = {c1, c2, ...., cnumSelect} 是你选择的列的集合。对于矩阵中的某一行 row ，如果满足下述条件，则认为这一行被集合 s 覆盖：

对于满足 matrix[row][col] == 1 的每个单元格 matrix[row][col]（0 <= col <= n - 1），col 均存在于 s 中，或者
row 中 不存在 值为 1 的单元格。
你需要从矩阵中选出 numSelect 个列，使集合覆盖的行数最大化。

返回一个整数，表示可以由 numSelect 列构成的集合 覆盖 的 最大行数 。

1 <= m, n <= 12

方法一：二进制枚举
用整数 S 表示选中列的集合
枚举选择列的全部情况，一共 2^n
对每一行，也用二进制表示，匹配的时候使用按位与  (mask[i] & cur) == mask[i] 判断是否覆盖了这一行

方法二：二进制枚举的 Gosper's Hack 优化
int cur = (1 << numSelect) - 1; // numSelect = 2, cur = 3 // 011

int lb = cur & -cur;  // 找到 lowest bit 最右边的 1
int r = cur + lb;     // cur + lowbit = r, 前半部分, 11 + 1 = 100
cur = ((r ^ cur) >> __builtin_ctz(lb) + 2) | r;  // __builtin_ctz 数零 (r ^ cur) 记录变化的位数

找到二进制串里的最后一个 01 ，把他变成 10 ，就是当前组合的下一个组合

 */
class Solution {
 public:
  int maximumRows(vector<vector<int>>& matrix, int numSelect) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> mask(m);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        mask[i] |= matrix[i][j] << j;
      }
    }
    int ans = 0, cur = 0;
    int end = (1 << n);
    while (++cur < end) {
      if (__builtin_popcount(cur) != numSelect) {
        continue;
      }
      int num = 0;
      for (int i = 0; i < m; i++) {
        if ((mask[i] & cur) == mask[i]) {
          num++;
        }
      }
      ans = max(ans, num);
    }
    return ans;
  }
};
int main() {
  int a = 408;
  cout << (a & -a) << endl;
  return 0;
}
