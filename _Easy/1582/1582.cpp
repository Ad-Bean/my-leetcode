
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

/* 
rows * cols mat[i][j] = 0 or 1 

if mat[i][j] == 1 and mat[i][:] == 0 and mat[:][j] == 0

方法一：rowsum[i] == 1 && colsum[j] == 1 && mat[i][j] == 0
时间复杂度 MN
空间复杂度 M+N

方法二：
空间复杂度 O(1) 修改原矩阵
*/
class Solution {
 public:
  int numSpecial(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<int> rs(m), cs(n);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        rs[i] += mat[i][j];
        cs[j] += mat[i][j];
      }
    }
    int sum = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 1 && rs[i] == 1 && cs[j] == 1) {
          sum++;
        }
      }
    }
    return sum;
  }
};
int main() {

  Solution test;
  return 0;
}