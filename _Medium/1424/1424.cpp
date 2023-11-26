#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// m x n
/* 
0,0            = 0
1,0 0,1        = 1
2,0 1,1 0,2    = 2
2,1 1,2        = 3
2,2            = 4

同一斜线，满足下标 i + j 相等
使用 map 从最后一行开始存储元素，map 是有序 nlogn
2,0 2,1 2,2 1,0 1,1 1,2 0,0 0,1 0,2 倒序，有序后变成

0,0 1,0 0,1 2,0 1,1 
倒序是因为，同样和 2,0 和 1,1 需要 2,0 先出现

顺序输出
*/

class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    map<int, vector<int>> mp;
    for (int i = nums.size() - 1; i >= 0; i--) {
      for (int j = 0; j < nums[i].size(); j++) {
        mp[i + j].emplace_back(nums[i][j]);
      }
    }

    vector<int> ans;
    for (const auto& [k, v] : mp) {
      for (const auto& val : v) {
        ans.emplace_back(val);
      }
    }
    return ans;
  }
};
int main() {
  //   vector<vector<int>> nums = {{1, 2, 3, 4, 5}, {6, 7}, {8}, {9, 10, 11}, {12, 13, 14, 15, 16}};
  //   vector<vector<int>> nums = {
  //       {20, 17, 13, 14},
  //       {12, 6},
  //       {3, 4},
  //   };
  vector<vector<int>> nums = {
      {14, 12, 19, 16, 9},
      {13, 14, 15, 8, 11},
      {11, 13, 1},
  };
  Solution test;
  vector<int> ans = test.findDiagonalOrder(nums);
  for (const auto& a : ans) {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}