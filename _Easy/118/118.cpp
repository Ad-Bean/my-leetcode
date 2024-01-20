#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。

方法一：模拟


 */
class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans(numRows);
    for (int i = 0; i < numRows; i++) {
      ans[i] = vector<int>(i + 1);
      ans[i][0] = ans[i][i] = 1;
      for (int j = 1; j < i; j++) {
        ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}
