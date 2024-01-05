#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {
      return 1;
    }
    vector<int> dp;
    int ans = 1;
    for (int i = 0; i < n; i++) {
      // 第一个大于等于的位置，因为是严格递增
      auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
      if (it == dp.end()) {
        dp.emplace_back(nums[i]);
        ans = max(ans, (int)(dp.size()));
      } else {
        *(it) = nums[i];
        ans = max(ans, (int)(it - dp.begin()));
      }
    }
    return ans;
  }
};

int main() {
  //   vector<int> t = {2, 2, 3, 5};
  //   cout << *(lower_bound(t.begin(), t.end(), 3)) << endl;

  Solution test;
  vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
  cout << test.lengthOfLIS(nums) << endl;
  return 0;
}