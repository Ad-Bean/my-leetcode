#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
/* 

输入：nums = [1,2,3,4,5]
输出：6

数组变成 [3,3,3,3,3] 需要执行 4 次特殊操作，代价为 |1 - 3| + |2 - 3| + |4 - 3| + |5 - 3| = 6 。

输入：nums = [10,12,13,14,15]
输出：11
数组变成 [11,11,11,11,11]


[301, 309 , 312, 322]

303  303    303  303
2  + 6 + 9 + 19 = 8+28 = 36
313  313    313  313
12 + 4   + 1 +  9 = 10+16 = 26

[101, 104, 107, 126, 130]
 121  121  121  121  121
 111  111  111  111  111
  10 + 7  + 4 +  15 + 19 = 55


方法一：找到最近的回文数
[1,2,3,4,5] 都是个位，sum / n = 3
[10,12,13,14,15] sum/n = 64/5 = 12  -> 11
[22,33,22,33,22] sum/n = 26  -> 22 
[101,104,107,126,130] sum/n = 568/5 = 113 -> 111
[307,321,322,327] sum/n = 1277/4 = 319 -> 323

[4,3,1]  sum / n = 8/3 = 2
[4,2,1]  sum / n = 7/3 = 2  
[4,1,1]  sum / n = 6/3 = 2  -> 1

[101,102,105,108,124]  avg = 108, median = 105


[301,309,312,322]  median = 310  -> 313

[101,115,116,120,122] median = 116 -> 111, 121
*/
class Solution {
  typedef long long ll;

  bool isPalindrome(ll x) {
    if (x % 10 == 0) {  // 0 或 10
      return false;
    }
    ll val = 0;
    for (ll i = x; i; i /= 10) {
      val = val * 10 + i % 10;  // 从后往前构造新数字
    }
    return val == x;
  }

  ll findLesser(ll x) {
    while (!isPalindrome(x)) {
      --x;
    }
    return x;
  }

  ll findGreater(ll x) {
    while (!isPalindrome(x)) {
      ++x;
    }
    return x;
  }

 public:
  long long minimumCost(vector<int>& nums) {
    int n = nums.size();
    ll sum = accumulate(nums.begin(), nums.end(), 0LL);
    sort(nums.begin(), nums.end());

    ll l = findLesser(nums[n >> 1]);
    ll r = findGreater(nums[n >> 1]);
    ll res1 = 0, res2 = 0;
    for (const auto& i : nums) {
      res1 += abs(i - l);
      res2 += abs(i - r);
    }
    return min(res1, res2);
  }
};
int main() {

  Solution test;
  vector<int> nums = {22, 33, 22, 33, 22};
  cout << test.minimumCost(nums) << endl;
  return 0;
}