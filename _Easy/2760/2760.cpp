#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
从后往前枚举 l -> dp
dp[l] = 0, if nums[l] > threshold
dp[l] = dp[l+1] + 1, if nums[l] <= threshold && nums[l] % 2 != nums[l+1] % 2
dp[l] = 1, if nums[l] <= threshold && nums[l] % 2 == nums[l+1] % 2

其中 l == n - 1 和 else 情况都表示随意一个结尾
 */
class Solution {
 public:
  int longestAlternatingSubarray(vector<int>& nums, int threshold) {
    int n = nums.size();
    int ans = 0;
    int dp = 0;
    for (int l = n - 1; l >= 0; l--) {
      if (nums[l] > threshold) {
        dp = 0;
      } else if (l == n - 1 || (nums[l] ^ nums[l + 1]) & 1) {
        dp++;
      } else {
        dp = 1;
      }
      if ((nums[l] & 1) == 0) {
        ans = max(ans, dp);
      }
    }
    return ans;
  }
};
/* 
从最左边一个偶数开始-> 贪心

先找到第一个偶数小于 threshold
往后找
l = r 就是贪心
 */
int longestAlternatingSubarray(vector<int>& nums, int threshold) {
  int n = nums.size();
  int ans = 0;
  for (int l{}, r{1}; l < n; l = r) {
    while (l < n and (nums[l] > threshold || (nums[l] & 1))) {
      l++;
    }
    if (l == n) {
      break;
    }
    r = l + 1;
    while (r < n && ((nums[r] ^ nums[r - 1]) & 1) && nums[r] <= threshold) {
      r++;
    }
    ans = max(ans, r - l);
  }

  return ans;
}

int main() {

  Solution test;
  vector<int> nums{2, 3, 3, 10};
  int threshold = 18;
  cout << test.longestAlternatingSubarray(nums, threshold) << endl;
  return 0;
}