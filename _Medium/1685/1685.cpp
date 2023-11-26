#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/* 
非递减 有序整数数组 nums
res[i] = sum(|nums[i]-nums[j]|)
[2,3,5]

res[0] = abs(nums[0] - nums[1]) + abs(nums[0] - nums[2]) = (0*nums[0] - 0) + (nums[0] + nums[1] + nums[2] - 3*nums[0])
       = 0 * 2 - 0 + 2+3+5 - 2*3 = 4

res[1] = abs(nums[0] - nums[1]) + abs(nums[1] - nums[2]) = (1*nums[1] - nums[0]) + (nums[1] + nums[2] - 2*nums[1])
       = 3 - 2 + 5 - 3 = 3 = 1*3-2 + 3+5 - 2*3= 3

res[2] = abs(nums[0] - nums[2]) + abs(nums[1] - nums[2]) = (2*nums[2] - nums[0] - nums[1]) + (nums[2] - 1*nums[2])
       = 2*5-5 + 5 - 5 = 5


 */
class Solution {
 public:
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int cur_sum = 0;
    int tot = accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size();
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      int a = i * nums[i] - cur_sum;
      int b = (tot - cur_sum) - ((n - i) * nums[i]);
      ans[i] = a + b;
      cur_sum += nums[i];
    }
    return ans;
  }
};

int main() {

  Solution test;
  vector<int> v = {2, 3, 5};
  vector<int> ans = test.getSumAbsoluteDifferences(v);
  for (const auto a : ans) {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}