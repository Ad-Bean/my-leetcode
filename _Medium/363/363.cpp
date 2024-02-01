/*
 * @lc app=leetcode.cn id=363 lang=cpp
 *
 * [363] 矩形区域不超过 K 的最大数值和
 *
 * https://leetcode.cn/problems/max-sum-of-rectangle-no-larger-than-k/description/
 *
 * 给你一个 m x n 的矩阵 matrix 和一个整数 k ，找出并返回矩阵内部矩形区域的不超过 k 的最大数值和。
 * 题目数据保证总会存在一个数值和不超过 k 的矩形区域。
 * 
 * 输入：matrix = [[1,0,1],[0,-2,3]], k = 2
 * 输出：2
 * 解释：蓝色边框圈出来的矩形区域 [[0, 1], [-2, 3]] 的数值和是 2，且 2 是不超过 k 的最大数字（k = 2）。
 * 
 * 输入：matrix = [[2,2,-1]], k = 3
 * 输出：3
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 100
 * -100 <= matrix[i][j] <= 100
 * -10^5 <= k <= 10^5
 * 
 * 进阶：如果行数远大于列数，该如何设计解决方案？
 * 
 * 方法一：前缀和 & 二分
 * 二维前缀和 + 枚举左上角和右下角 Om^2 n^2 可能超时 (vector 超时，函数外 int sum[110][110] 可以通过)
 * 换句话说是通过枚举 (i,j) 和 (p,q) 来唯一确定子矩阵的四条边，每个坐标点可以看作确定子矩阵的某条边。
 * 
 * 在 1. 两数之和 中可以暴力枚举两个数，也可以只枚举其中一个数，
 * 然后使用数据结构（哈希表）来加速找另一个数（这是一个通用的「降低枚举复杂度」思考方向）。
 * 即哈希记录所有 mp[nums[i]]++ 然后 On 找 mp[target - nums[i]]
 * 
 * 枚举三条边，使用哈希数据结构来加速找第四条边，即上下两行 + 左列
 * 比如当矩阵只有一行时，此时一维前缀和 area(i,j) = sum[j] - sum[i - 1]
 * 对题目 sum[j] - sum[i - 1] <= k 即 sum[j] <= k + sum[i - 1]
 * 枚举 i 时，查询一个下标 j 符合这个不等式，由于前缀和非递减，可以使用二分
 * 
 * 将一维思路应用到本题（二维），复杂度要么是 O(m^2∗n*log⁡n) 要么是 O(n^2∗m*log⁡m)
 * 
 * 固定枚举「上下行」和「右边列」，这时候唯一能够确定一个子矩阵则是取决于「左边列」：
 * 
 *「目标子矩阵的和」等于「子矩阵的右边列 与 原矩阵的左边列 形成的子矩阵和」-「子矩阵左边列 与 原矩阵左边列 形成的子矩阵和」
 * 
 * area[r] - area[l-1] = 子矩阵的和 = target <= k
 * 此时 area[r] 左上角 (top, 0) 右下角 (bottom,r)
 * sum[bottom][r] - sum[bottom][0] - sum[top][r] + sum[top][0] 
 *                               = sum[bottom][r] - sum[top][r]
 * 
 * 已知 area[r] 和 k，求 area[r] - k <= area[l - 1] 且由于 r >= l -1 所以可以一边哈希一边二分
 * 
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
// @lc code=start
class Solution {
 public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> sum(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
      }
    }
    // bool isRight = n > m;  // 判断行 还是 列大，减少二分
    // 枚举上下边界和右列
    int ans = INT_MIN;
    for (int top = 1; top <= m; top++) {
      for (int bot = top; bot <= m; bot++) {
        set<int> st;
        st.emplace(0);
        for (int r = 1; r <= n; r++) {
          int right = sum[bot][r] - sum[top - 1][r];
          auto left = st.lower_bound(right - k);  // 第一个大于等于 area[r] - k 的左侧和
          if (left != st.end()) {                 // 存在
            ans = max(ans, right - *left);        // 子矩阵和 area[r] - area[l-1]
          }                                       //
          st.insert(right);                       // 遍历时哈希当前的面积
        }
      }
    }
    return ans;
  }
};
// @lc code=end
