#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
 public:
  vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
    int n = parents.size();
    vector<int> ans(n, 1);
    auto it = find(nums.begin(), nums.end(), 1);
    // 都小于 1，则返回全是 1
    if (it == nums.end()) {
      return ans;
    }

    //建图：parents[i] -> i
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
      g[parents[i]].emplace_back(i);
    }

    unordered_set<int> vis;
    function<void(int)> dfs = [&](int i) -> void {
      vis.insert(nums[i]);
      for (int child : g[i]) {
        if (!vis.count(nums[child])) {
          dfs(child);
        }
      }
    };

    // 缺失的最小基因是 2
    int minn = 2;
    // 第一个为 1 的节点
    int node = it - nums.begin();
    while (node >= 0) {
      // 记录该子树的所有基因值，如果该值没见过，继续遍历
      dfs(node);
      // 得到最小的那个基因值
      while (vis.count(minn)) {
        minn++;
      }
      ans[node] = minn;
      // 向上遍历其祖先
      node = parents[node];
    }
    return ans;
  }
};
int main() {
  Solution test;
  vector<int> parents{-1, 0, 1, 0, 3, 3};
  vector<int> nums{5, 4, 6, 2, 1, 3};
  vector<int> ans = test.smallestMissingValueSubtree(parents, nums);
  for (auto a : ans) {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}