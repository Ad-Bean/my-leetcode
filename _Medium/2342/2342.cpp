#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
two sum

nums[i] <= 1e9 数位和，最多 9 * 9 = 81
 */
class Solution {
 public:
  int maximumSum(vector<int>& nums) {
    int mp[82]{};
    int ans = -1;
    for (const int& num : nums) {
      int temp = num;
      int sum = 0;
      while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
      }
      if (mp[sum]) {
        ans = max(ans, mp[sum] + num);
      }
      mp[sum] = max(num, mp[sum]);
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}