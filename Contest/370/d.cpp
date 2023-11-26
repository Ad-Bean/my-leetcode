#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
 public:
  long long maxBalancedSubsequenceSum(vector<int>& nums) {
    int n = nums.size();
    vector<ll> dp(n);
    ll maxSum = 0;

    for (int i = 0; i < n; ++i) {
      dp[i] = nums[i];
      for (int j = 0; j < i; ++j) {
        if (nums[i] - nums[j] >= i - j) {
          dp[i] = max(dp[i], dp[j] + nums[i]);
        }
      }
      maxSum = max(maxSum, dp[i]);
    }

    return maxSum;
  }
};
int main() {

  Solution test;
  return 0;
}