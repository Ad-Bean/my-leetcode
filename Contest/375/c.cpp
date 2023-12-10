#include <bits/stdc++.h>
using namespace std;
/* 
给你一个整数数组 nums 和一个 正整数 k 。

请你统计有多少满足 「 nums 中的 最大 元素」至少出现 k 次的子数组，并返回满足这一条件的子数组的数目。

子数组是数组中的一个连续元素序列。

[28,5,58,91,24,91,53,9,48,85,16,78,91,91,47,91,61,4,54,61,49]
1
          3     5                  12 13    15 
ans = 187

[21,11,13,15,16,21,8,9,6,21]
2
 0              5        9
ans = 10, 1 + 1 + 1 + 1 + 1 + 5 
方法一：
记录最大值出现的下标，mp[频数] = 下标
如果当前频数 >= k，则 mp[当前频数 - 目标频数 + 1] + 1，上一次出现的下标 + 1，就是满足目标的子序列

 */
class Solution {
  typedef long long ll;
  typedef pair<int, int> pii;

 public:
  long long countSubarrays(vector<int>& nums, int k) {
    ll ans = 0;
    int n = nums.size();
    int maxx = *max_element(nums.begin(), nums.end());
    vector<int> pre(n);
    for (int i = 0; i < n; i++) {
      pre[i] = (nums[i] == maxx) ? 1 : 0;
    }

    unordered_map<int, int> mp;
    mp[0] = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += pre[i];
      if (mp.find(cnt) == mp.end()) {
        mp[cnt] = i;
      }
      if (cnt >= k && mp.find(cnt - k + 1) != mp.end()) {
        cout << cnt - k + 1 << " " << mp[cnt - k + 1] << endl;
        ans += mp[cnt - k + 1] + 1;
      }
    }
    return ans;
  }
};

int main() {

  Solution test;

  vector<int> nums = {21, 11, 13, 15, 16, 21, 8, 9, 6, 21};
  int k = 2;
  cout << test.countSubarrays(nums, k) << endl;
  return 0;
}