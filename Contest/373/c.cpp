#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
 public:
  vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    int n = nums.size();
    vector<int> ans(n);
    vector<pair<int, int>> ss;
    for (int i = 0; i < n; i++) {
      ss.push_back({nums[i], i});
    };
    sort(ss.begin(), ss.end());
    for (const auto& a : ss) {
      cout << a.first << " " << a.second << ", ";
    }
    cout << endl;
    for (int i = 0; i < n;) {
      int j = i + 1;
      while (j < n && ss[j].first - ss[j - 1].first <= limit) {
        j++;
      }
      vector<int> q;
      for (int k = i; k < j; k++) {
        q.emplace_back(ss[k].second);
      }

      sort(q.begin(), q.end());

      for (int k = i; k < j; k++) {
        ans[q[k - i]] = ss[k].first;
      }
      i = j;
    }
    return ans;
  }
};

int main() {

  Solution test;
  vector<int> nums = {1, 5, 3, 9, 8};
  int limit = 2;
  vector<int> ans = test.lexicographicallySmallestArray(nums, limit);
  for (const int& a : ans) {
    cout << a << " ";
  }
  return 0;
}