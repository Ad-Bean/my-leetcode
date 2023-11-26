#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
没法用哈希表

但是可以排序双指针


-6,2,5,-2,-7,-1,3  t = -2


-7 -6 -2 -1 2 3 5
i=0          j=5
ans += 5 (-7 到 3 这个区间都满足)
   i=1       j=5
ans += 4
      i=2 j=3
ans += 1
 */
class Solution {
 public:
  int countPairs(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0, j = nums.size() - 1; i < j; i++) {
      while (i < j && nums[i] + nums[j] >= target) {
        j--;
      }
      ans += j - i;
    }
    return ans;
  }
};

int main() {

  Solution test;
  return 0;
}