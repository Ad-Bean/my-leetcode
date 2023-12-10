#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个下标从 0 开始、由 正整数 组成的数组 nums。

将数组分割成一个或多个 连续 子数组，如果不存在包含了相同数字的两个子数组，则认为是一种 好分割方案 。

返回 nums 的 好分割方案 的 数目。

由于答案可能很大，请返回答案对 1e9 + 7 取余 的结果。


输入：nums = [1,2,3,4]
输出：8
解释：有 8 种 好分割方案 ：
([1], [2], [3], [4]),
([1], [2], [3,4]),
([1], [2,3], [4]),
([1], [2,3,4]),
([1,2], [3], [4]),
([1,2], [3,4]),
([1,2,3], [4]),
([1,2,3,4]) 

 */
class Solution {
  const int mod = 1e9 + 7;
  ll powerModulo(ll a, ll b, ll m) {
    ll result = 1LL;
    a = a % m;

    while (b > 0) {
      if (b & 1) {
        result = (result * a) % m;
      }
      b = b / 2;
      a = (a * a) % m;
    }

    return result;
  }

 public:
  int numberOfGoodPartitions(vector<int>& nums) {
    int n = nums.size();

    unordered_map<int, vector<int>> mp;
    vector<pii> seg;
    for (int i = 0; i < n; i++) {
      mp[nums[i]].emplace_back(i);
    }
    for (const auto& v : mp) {
      int start = v.second[0], end = v.second.back();
      seg.push_back({start, end});
    }
    sort(seg.begin(), seg.end(), [&](const auto& a, const auto& b) -> bool {
      if (a.first != b.first) {
        return a.first < b.first;
      }
      return a.second < b.second;
    });
    int l = 0, r = 0;
    ll cnt = 0;
    for (const auto& pi : seg) {
      int st = pi.first, en = pi.second;
      if (r < st) {
        cnt += (r - l > 0) ? 2 : 1;
        l = st;
        r = st;
      } else if (r == st) {
        cnt += (r - l > 0) ? 1 : 0;
        l = st;
        r = st;
      }
      r = max(r, en + 1);
    }
    cnt += (r - l > 0) ? 1 : 0;
    return powerModulo(2LL, cnt - 1, mod);
  }
};
int main() {

  Solution test;
  vector<int> nums = {1, 2, 3, 4};

  cout << test.numberOfGoodPartitions(nums) << endl;
  return 0;
}