#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个下标从 0 开始长度为 n 的数组 nums 。

每一秒，你可以对数组执行以下操作：

对于范围在 [0, n - 1] 内的每一个下标 i ，将 nums[i] 替换成 nums[i] ，nums[(i - 1 + n) % n] 或者 nums[(i + 1) % n] 三者之一。
注意，所有元素会被同时替换。

请你返回将数组 nums 中所有元素变成相等元素所需要的 最少 秒数。

输入：nums = [1,2,1,2]
输出：1
解释：我们可以在 1 秒内将数组变成相等元素：
- 第 1 秒，将每个位置的元素分别变为 [nums[3],nums[1],nums[3],nums[3]] 。变化后，nums = [2,2,2,2] 。
1 秒是将数组变成相等元素所需要的最少秒数。

方法一：枚举 + 哈希 On
对每个 i 变成自己、左边或者右边
枚举所有答案，即让数组变成 nums[i] 的最小秒数
对于 nums[i] 自己不用变，但其他数字要变，
    所以对每个它的坐标，可以在一秒内改变左右，求出这个值就可以
比如 2,1,3,3,2
如果将 nums 全部变成 2
2 出现的下标是 0, 4
0 可以在第一秒感染 4 和 1，4 在第一秒感染 3 和 0
求出 4 和 0 的差，然后除去 2 则是需要的时间

所以变成这个数的时间就是最大间距 / 2

如果只有一个下标，则需要 n 秒扩散
如果只有两个下标，则需要 i + (n - back) 秒扩散
如果有多个下标，同理需要 i + (n - back) 秒扩散

由于是遍历所有索引，实际上时间复杂度是 On
 */
class Solution {
 public:
  int minimumSeconds(vector<int>& nums) {
    unordered_map<int, vector<int>> mp;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      mp[nums[i]].emplace_back(i);
    }
    int ans = n;
    for (const auto& [k, v] : mp) {
      // 将 nums 全部变成 k
      // 首尾扩散需要 (front + n - back) / 2
      int ms = v.front() + (n - v.back());
      // 中间的扩散
      for (int i = 1; i < v.size(); i++) {
        ms = max(ms, v[i] - v[i - 1]);
      }
      ans = min(ans, ms / 2);
    }
    return ans;
  }
};
int main() {

  Solution test;
  vector<int> nums = {2, 1, 3, 3, 2};
  cout << test.minimumSeconds(nums) << endl;
  return 0;
}
