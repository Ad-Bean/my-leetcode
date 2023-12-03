#include <bits/stdc++.h>
using namespace std;

/* 
1,4,10

t = 19

dp[0] = 0
dp[1]

dp[i] 表示金额 i 能够被组成的最小硬币数目
 */
class Solution {
  typedef long long ll;

 public:
  int minimumAddedCoins(vector<int>& coins, int target) {
    sort(coins.begin(), coins.end());
    ll ans = 0;
    ll cur = 0;
    for (const int& coin : coins) {
      if (cur + 1 >= coin) {
        cur += coin;
      } else {
        while (cur + 1 < coin) {
          cur += (cur + 1);
          ans++;
        }
        cur += coin;
      }
    }
    while (cur < target) {
      cur += (cur + 1);
      ans++;
    }
    return ans;
  }
};

int main() {

  Solution solution;

  // 示例 1
  std::vector<int> coins1 = {1, 4, 10};
  int target1 = 19;
  std::cout << solution.minimumAddedCoins(coins1, target1) << std::endl;

  // 示例 2
  std::vector<int> coins2 = {1, 4, 10, 5, 7, 19};
  int target2 = 19;
  std::cout << solution.minimumAddedCoins(coins2, target2) << std::endl;

  // 示例 3
  std::vector<int> coins3 = {1, 1, 1};
  int target3 = 20;
  std::cout << solution.minimumAddedCoins(coins3, target3) << std::endl;

  return 0;
  return 0;
}