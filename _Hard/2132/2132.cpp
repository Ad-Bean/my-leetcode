#include <bits/stdc++.h>
using namespace std;
/* 
给你一个 m x n 的二进制矩阵 grid ，每个格子要么为 0 （空）要么为 1 （被占据）。

给你邮票的尺寸为 stampHeight x stampWidth 。我们想将邮票贴进二进制矩阵中，且满足以下 限制 和 要求 ：

覆盖所有 空 格子。 0
不覆盖任何 被占据 的格子。 1
我们可以放入任意数目的邮票。
邮票可以相互有 重叠 部分。
邮票不允许 旋转 。
邮票必须完全在矩阵 内 。
如果在满足上述要求的前提下，可以放入邮票，请返回 true ，否则返回 false 。

前置一：一维前缀和 -> 二维前缀和
一维：pre[i + 1] = pre[i] + m[i] 

二维前缀和：
定义 pre[i + 1][j + 1] 表示左上角 m[0][0] 到 m[i][j] 子矩阵元素和
pre[i + 1][j + 1] = pre[i + 1][j] + pre[i][j + 1] - 重复子矩阵 pre[i][j] + m[i][j]

1 2 3       1 2      1 2 3     1 2
4 5 6   =   4 5   +  4 5 6  -  4 5  +  
7 8 9       7 8                            9

求子矩阵和：

m[r1][c1] 到 m[r2-1][c2-1]  = pre[r2][c2] - pre[r2][c1] - pre[r1][c2] + 重复子矩阵 pre[r1][c1]

            1 2 3     1     1 2 3    1
  5 6   =   4 5 6  -  4  -        +  
  8 9       7 8 9     7                   

前置二：差分数组

一维差分：
d[i] = a[i] - a[i - 1] 并且补上 a[0]
a=[1,3,3,5,8]
d=[1,2,0,2,3] 如果从左到右累加，则能还原 a

a'=[1,13,13,15,8] a[1:3] 都加 10
d'=[1,12,0,2,−7] d'是 d[1] + 10 和 d[4] - 10 得到 

对 a 中连续子数组的操作，可以转变成对差分数组 d 中两个数的操作。


二维差分：

对 m[i1][j1] 到 m[i2][j2] 区域加 1 的操作等于更新 差分矩阵 中四个位置的差分值
        j1    j2               j1    j2 j2+1           
                                                                                                          
i1      +1 +1 +1       i1      +1 +1 +1 -1 -1 
        +1 +1 +1               +1                      
        +1 +1 +1               +1                    
        +1 +1 +1   =           +1                         
        +1 +1 +1               +1                    
        +1 +1 +1               +1                    
        +1 +1 +1               +1                    
i2      +1 +1 +1       i2      +1                    
                       i2+1    -1        +1 +1                
                               -1        +1 +1      


d[i1][j1] + 1
d[i1][j2 + 1] - 1
d[i2+1][j1] - 1
d[i2+1][j2+1] + 1

方法一：二维前缀和

贪心策略：由于邮票可以重叠一部分，那么能放就放
判断放完：假设用 cnt[][] 记录每个空格子被多少张邮票覆盖，如果存在一个空的就返回 false
遍历位置：遍历所有能放邮票的位置

1. 判断一个矩形区域可以放邮票：二维前缀和， O(1) 查询区域和，0 则表示全 0 可以放
2. 判断最后邮票放满空格子：放邮票时，把 cnt[][] 的子矩阵每个区域 +1，可以用二维差分矩阵对该区域 +1， O(1) 更新
3. 遍历检查：还原二维差分矩阵，对二维差分矩阵求前缀和，如果有一个空格子为 0 则没有被覆盖，返回 false
 */
typedef long long ll;
typedef pair<int, int> pii;

class Solution {
 public:
  bool possibleToStamp(vector<vector<int>>& grid, int h, int w) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> pre(m + 1, vector<int>(n + 1));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        pre[i + 1][j + 1] = pre[i + 1][j] + pre[i][j + 1] - pre[i][j] + grid[i][j];
      }
    }

    // 计算子矩阵和，二维差分
    vector<vector<int>> d(m + 2, vector<int>(n + 2));
    for (int i = h; i <= m; i++) {
      for (int j = w; j <= n; j++) {
        // 子矩阵 [i-h][j-w] 到 [i][j] 全是 0，可以放邮票
        if (pre[i][j] - pre[i][j - w] - pre[i - h][j] + pre[i - h][j - w] == 0) {
          // 子矩阵 [i-h][j-w] 到 [i][j] 全 + 1，向后移动一位，为了二位前缀和复原
          d[i - h + 1][j - w + 1]++;
          d[i - h + 1][j + 1]--;
          d[i + 1][j - w + 1]--;
          d[i + 1][j + 1]++;
        }
      }
    }
    // 计算二维差分矩阵前缀和
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        // [0][0] 到 [i][j] 求二维前缀和，
        d[i + 1][j + 1] += d[i][j + 1] + d[i + 1][j] - d[i][j];
        if (grid[i][j] == 0 && d[i + 1][j + 1] == 0) {
          return false;
        }
      }
    }

    return true;
  }
};
int main() {
  vector<vector<int>> grid = {
      {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0},
  };
  int h = 4, w = 3;

  Solution test;
  cout << test.possibleToStamp(grid, h, w) << endl;
  return 0;
}

/* 
二维差分
0 1 0 0 -1 
0 1 0 0 -1

复原，二维前缀和


 */