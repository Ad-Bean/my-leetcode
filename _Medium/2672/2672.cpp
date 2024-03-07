#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个下标从 0 开始、长度为 n 的数组 nums 。一开始，所有元素都是 未染色 （值为 0 ）的。

给你一个二维整数数组 queries ，其中 queries[i] = [indexi, colori] 。

对于每个操作，你需要将数组 nums 中下标为 indexi 的格子染色为 colori 。

请你返回一个长度与 queries 相等的数组 answer ，其中 answer[i]是前 i 个操作 之后 ，相邻元素颜色相同的数目。

更正式的，answer[i] 是执行完前 i 个操作后，0 <= j < n - 1 的下标 j 中，满足 nums[j] == nums[j + 1] 且 nums[j] != 0 的数目。

输入：n = 4, queries = [[0,2],[1,2],[3,1],[1,1],[2,1]]
输出：[0,1,1,0,2]
解释：一开始数组 nums = [0,0,0,0] ，0 表示数组中还没染色的元素。
- 第 1 个操作后，nums = [2,0,0,0] 。相邻元素颜色相同的数目为 0 。
- 第 2 个操作后，nums = [2,2,0,0] 。相邻元素颜色相同的数目为 1 。
- 第 3 个操作后，nums = [2,2,0,1] 。相邻元素颜色相同的数目为 1 。
- 第 4 个操作后，nums = [2,1,0,1] 。相邻元素颜色相同的数目为 0 。
- 第 5 个操作后，nums = [2,1,1,1] 。相邻元素颜色相同的数目为 2 。

方法一：线段树
单点修改，区间查询


方法二：模拟
每次修改，只需要判断相邻

 */
class Solution {
 public:
  vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
    int sz = queries.size();
    vector<int> ans(sz);
    vector<int> colors(n + 2);                             // 模拟，加上前后避免越界
    int cnt = 0;                                           // 相邻相同的个数
    for (int i = 0; i < sz; i++) {                         // 遍历每次修改
      int idx = queries[i][0] + 1, color = queries[i][1];  // +1 避免越界
      if (colors[idx]) {                                   // 如果已经有颜色，需要更新相邻
        cnt -= (colors[idx] == colors[idx - 1]) +          //
               (colors[idx] == colors[idx + 1]);           // 更新相邻
      }                                                    //
      colors[idx] = color;                                 //
      cnt += (colors[idx] == colors[idx - 1]) +            //
             (colors[idx] == colors[idx + 1]);             // 更新相邻
      ans[i] = cnt;                                        //
    }
    return ans;
  }
};
int main() {

  Solution test;
  int n = 4;
  vector<vector<int>> queries = {{0, 2}, {1, 2}, {3, 1}, {1, 1}, {2, 1}};
  auto ans = test.colorTheArray(n, queries);
  for (auto x : ans) {
    cout << x << " ";
  }
  return 0;
}
