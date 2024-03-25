#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
Given an integer array nums,
return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, 
and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
3 <= nums.length <= 3000

方法一：双指针 + 排序
暴力：O(n^3) 三重枚举，超时
思考 2sum 做法，一遍枚举，用哈希表存 mp[nums[i]]，用哈希表找 mp[target-nums[i]]
对于 3sum，可以尝试两遍枚举，比如当前是 nums[i] 那么就是找 -nums[i] = nums[j] + nums[k] 2sum
但是这样会有重复，需要去重

所以先排序，对每个 nums[i] 如果和上一个相同则可以跳过，同时对答案也需要用哈希表去重
但问题来了，如果已经排序了，就可以用双指针来优化空间复杂度

排序后，对于每个 nums[i]，使用双指针 l = i + 1, r = n - 1
如果 nums[i] + nums[l] + nums[r] == 0，那么就是答案
如果 nums[i] + nums[l] + nums[r] < 0，说明 l 太小，l++
如果 nums[i] + nums[l] + nums[r] > 0，说明 r 太大，r--
由于已经排序，去重变得简单：nums[i] == nums[i-1]，nums[l] == nums[l-1]，nums[r] == nums[r+1] 都可以跳过

*/

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      if (nums[i] + nums[i + 1] + nums[i + 2] > 0) {
        break;  // 全部是正数，后面没有能使得和为 0 的
      }
      if (nums[i] + nums[n - 2] + nums[n - 1] < 0) {
        continue;  // 全部是负数，没有能使得和为 0 的
      }
      int l = i + 1, r = n - 1;
      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        if (sum < 0) {
          l++;
        } else if (sum > 0) {
          r--;
        } else if (sum == 0) {
          ans.push_back({nums[i], nums[l++], nums[r--]});
          while (l < r && nums[l] == nums[l - 1]) {
            l++;
          }
          while (l < r && nums[r] == nums[r + 1]) {
            r--;
          }
        }
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  vector<int> nums = {0, 0, 0, 0};
  vector<vector<int>> ans = test.threeSum(nums);
  for (auto& v : ans) {
    for (int x : v) {
      cout << x << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
