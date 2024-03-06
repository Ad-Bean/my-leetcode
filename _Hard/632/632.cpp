#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
你有 k 个 非递减排列 的整数列表。
找到一个 最小 区间，使得 k 个列表中的每个列表至少有一个数包含在其中。

我们定义如果 b-a < d-c 或者在 b-a == d-c 时 a < c，则区间 [a,b] 比 [c,d] 小。

输入：nums = [[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
输出：[20,24]
解释： 
列表 1：[4, 10, 15, 24, 26]，24 在区间 [20,24] 中。
列表 2：[0, 9, 12, 20]，20 在区间 [20,24] 中。
列表 3：[5, 18, 22, 30]，22 在区间 [20,24] 中。

方法一：K路归并 + 滑动窗口
归并后，记录对应组号，然后滑动窗口
保证窗口里满足 k 个组，维护最小区间

 */
class Solution {
  typedef pair<int, int> pii;

 public:
  vector<int> smallestRange(vector<vector<int>>& nums) {
    vector<pii> idx;
    int k = nums.size();
    for (int i = 0; i < k; i++) {
      for (auto& x : nums[i]) {
        idx.emplace_back(x, i);
      }
    }
    sort(idx.begin(), idx.end(), [&](const pii& a, const pii& b) { return a.first < b.first; });
    vector<int> ans;
    unordered_map<int, int> mp;  // 统计窗口内的组数，是否满足 k 个组
    int l = 0;
    int m = idx.size();
    int cnt = 0;
    for (int r = 0; r < m; r++) {
      mp[idx[r].second]++;
      if (mp[idx[r].second] == 1) {      // 第一次见这个组
        cnt++;                           //
      }                                  //
      if (cnt == k) {                    //
        while (mp[idx[l].second] > 1) {  //
          --mp[idx[l++].second];         // 留一个
        }
        if (ans.empty()) {
          ans.emplace_back(idx[l].first);
          ans.emplace_back(idx[r].first);
        } else if (ans[1] - ans[0] > idx[r].first - idx[l].first) {
          ans[0] = idx[l].first;
          ans[1] = idx[r].first;
        } else if ((ans[1] - ans[0] == idx[r].first - idx[l].first) && ans[0] > idx[r].first) {
          ans[0] = idx[l].first;
          ans[1] = idx[r].first;
        }
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}
