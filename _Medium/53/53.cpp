#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
dp[i] 表示到 i 位置的连续子数组最大和

dp[i] = max(dp[i - 1] + nums[i], nums[i])

 */
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    int ans = nums[0];
    for (int i = 1; i < n; i++) {
      dp[i] = max(dp[i - 1] + nums[i], nums[i]);
      ans = max(ans, dp[i]);
    }
    return max(ans, dp[n - 1]);
  }
};

int main() {

  Solution test;
  return 0;
}