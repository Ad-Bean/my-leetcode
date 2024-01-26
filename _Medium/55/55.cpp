/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 *
 * https://leetcode.cn/problems/jump-game/description/
 *
 *
 * 给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 
 * 判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 输入：nums = [2,3,1,1,4]
 * 输出：true
 * 解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
 * 
 * 输入：nums = [3,2,1,0,4]
 * 输出：false
 * 解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
 * 
 * 
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 10^5
 * 
 * 方法一：贪心
 * 维护一个数字 r，表示当前可以抵达最远的下标
 * 遍历数组，如果 当前下标 小于等于 r ，就表示可以跳到这，并且更新 r
 * 如果 r 大于等于 n-1 则返回 true
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
// @lc code=start
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int r = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (i <= r) {
        r = max(r, i + nums[i]);
      }
      if (r >= n - 1) {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end
