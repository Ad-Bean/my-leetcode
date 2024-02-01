#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个下标从 0 开始的数组 nums ，数组长度为 n 。

nums 的 不同元素数目差 数组可以用一个长度为 n 的数组 diff 表示，
其中 diff[i] 等于前缀 nums[0, ..., i] 中不同元素的数目 减去 后缀 nums[i + 1, ..., n - 1] 中不同元素的数目。

返回 nums 的 不同元素数目差 数组。

注意 nums[i, ..., j] 表示 nums 的一个从下标 i 开始到下标 j 结束的子数组（包含下标 i 和 j 对应元素）。特别需要说明的是，如果 i > j ，则 nums[i, ..., j] 表示一个空子数组。

方法一：前后缀和
如何知道 nums[i] 前面或者后面 有多少个不同的元素？set/哈希

方法二：桶/位计算
数据范围很小
1 <= n == nums.length <= 50
1 <= nums[i] <= 50
*/

class Solution {
 public:
  vector<int> distinctDifferenceArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> pre(n), suf(n + 1);  // 注意大小
    unordered_set<int> st;
    for (int i = n - 1; i >= 0; i--) {
      st.emplace(nums[i]);
      suf[i] = st.size();
    }

    st.clear();
    for (int i = 0; i < n; i++) {
      st.emplace(nums[i]);
      pre[i] = st.size() - suf[i + 1];
    }
    return pre;
  }
};
int main() {

  Solution test;
  vector<int> nums = {1, 2, 3, 4, 5};
  auto ans = test.distinctDifferenceArray(nums);
  for (const auto& a : ans) {
    cout << a << " ";
  }
  return 0;
}
