#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
 public:
  int minPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n / 2; i++) {
      ans = max(nums[i] + nums[n - i - 1], ans);
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}

/* 
最大数对和，然后最小
直接排序，kth max + kth min 就是最小数对
[3,5,2,3]
[2,3,3,5] -> [2,5] [3,3]

[3,5,4,2,4,6]
[2,3,4,4,5,6] -> [2,6], [3,5], [4,4]
 */