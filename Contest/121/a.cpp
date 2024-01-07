#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution {
 public:
  int missingInteger(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, bool> mp;
    int sum = nums[0];
    mp[nums[0]] = true;
    bool flag = true;
    for (int i = 1; i < n; i++) {
      if (nums[i] != nums[i - 1] + 1) {
        flag = false;
      }
      if (flag) {
        sum += nums[i];
      }
      mp[nums[i]] = true;
    }
    for (int i = sum; i < 2501; i++) {
      if (mp[i]) {
        continue;
      }
      return i;
    }
    return -1;
  }
};
int main() {
  vector<int> nums = {4, 5, 6, 7, 8, 8, 9, 4, 3, 2, 7};
  Solution test;
  cout << test.missingInteger(nums) << endl;
  return 0;
}