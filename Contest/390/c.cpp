#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
  typedef pair<int, int> pii;

 public:
  vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
    vector<long long> ans;
    int n = nums.size();
    unordered_map<int, int> cnt;
    unordered_map<int, int> last_update;
    priority_queue<pair<long long, pii>, vector<pair<long long, pii>>> hp;
    for (int i = 0; i < n; i++) {
      last_update[nums[i]] = i;
      cnt[nums[i]] += freq[i];
      while (!hp.empty() && hp.top().second.second < last_update[hp.top().second.first]) {
        // 堆顶更新时间小于元素更新时间
        hp.pop();
      }
      hp.push({cnt[nums[i]], {nums[i], i}});
      ans.emplace_back(hp.top().first);
    }
    return ans;
  }
};
int main() {

  Solution test;
  vector<int> nums = {2, 3, 2, 1};
  vector<int> freq = {3, 2, -3, 1};
  vector<long long> ans = test.mostFrequentIDs(nums, freq);
  for (auto x : ans) {
    cout << x << " ";
  }
  return 0;
}