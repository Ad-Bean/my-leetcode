
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
cardPoints = [1,2,3,4,5,6,1], k = 3
ans = 12
每次行动，你可以从行的开头或者末尾拿一张卡牌，最终你必须正好拿 k 张卡牌。

方法一：
1. 考虑 dp
2. 两端的最大子数组和/最小连续子数组和，用贪心或者dp求最小连续子数组的和，再用总和减去它

方法二：
1. 最小化剩下的点数和（剩下的牌必是连续）
2. 计算长度为 n - k 的连续子数组的最小和

方法三：
1.  前 k 个数的和                  // 拿前 k 个
2.  前 k - 1 个数、后 1 个数的和    //
3.  前 k - 2 个数、后 2 个数的和
...
k+1. 后 k 个数的和                 //

更新 max(ans, cur_sum)
 */
class Solution {
 public:
  int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int cur_sum = accumulate(cardPoints.begin(), cardPoints.begin() + n - k, 0);
    int min_sum = cur_sum;
    for (int i = n - k; i < n; i++) {
      cur_sum = cur_sum + cardPoints[i] - cardPoints[i - (n - k)];
      min_sum = min(min_sum, cur_sum);
    }
    int tot = accumulate(cardPoints.begin(), cardPoints.end(), 0);
    return tot - min_sum;
  }
};
int main() {

  Solution test;
  return 0;
}