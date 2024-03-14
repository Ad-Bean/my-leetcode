#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
Given a binary array nums and an integer goal, 
return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

输入：nums = [1,0,1,0,1], goal = 2
输出：4
解释：
有 4 个满足题目要求的子数组：[1,0,1]、[1,0,1,0]、[0,1,0,1]、[1,0,1]


方法一：前缀和 + 哈希表
为了求 [i, j] 的和为 goal，可以用哈希表记录 mp[pre] 出现的个数
遍历到 pre 时，需要找 pre[j] - pre[i] == goal 而 pre[i] == pre[j] - goal 记录 pre[i] 出现的次数，答案加上这个数

注意：mp[0] = 1 初始化，遍历时先更新 pre，更新 ans += cnt[pre - goal] 然后再更新 cnt[pre]++
为了避免重复

方法二：滑动窗口
对每个 j，满足 pre[j] - pre[i] == goal 的 i 总是在 [0, j] 中
while (r < n) {
    curSum += nums[r];
    while (l1 <= r && curSum > goal) {
        curSum -= nums[l1++];
    }
    sum += nums[r];
    while (l2 <= r && sum >= goal) {
        sum -= nums[l2++];
    }
    ans += l2 - l1;
    r++;
}

其中两个左边界 l1 表示第一个满足 curSum > goal 的位置，l2 表示第一个满足 sum >= goal 的位置
l2 - l1 表示以 r 结尾的满足条件的子数组个数

 */
class Solution {
 public:
  int numSubarraysWithSum(vector<int>& nums, int goal) {
    int pre = 0;
    int ans = 0;
    unordered_map<int, int> cnt;
    cnt[0] = 1;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      pre += nums[i];
      ans += cnt[pre - goal];
      cnt[pre]++;
    }
    return ans;
  }
};
int main() {

  Solution test;
  vector<int> t = {0, 0, 0, 0, 0};
  cout << test.numSubarraysWithSum(t, 0) << endl;
  vector<int> t1 = {1, 0, 1, 0, 1};
  cout << test.numSubarraysWithSum(t1, 2) << endl;
  return 0;
}
