
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

/* 
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回 滑动窗口中的最大值 。

方法一：堆 + 自定义排序函数
维护一个大小为 k 的大顶堆，存入下标，用自定义 compare 函数，将下标对应的值大的放在堆顶
每次窗口向右移动，如果堆顶的下标不在窗口内，就弹出堆顶
*/

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    auto cmp = [&](int a, int b) {
      return nums[a] < nums[b];
    };
    priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < k; i++) {
      q.emplace(i);
    }
    ans.emplace_back(nums[q.top()]);

    for (int i = k; i < n; i++) {
      q.emplace(i);
      while (q.top() + k <= i) {  // 最大的值的下标 在当前窗口外
        q.pop();
      }
      ans.emplace_back(nums[q.top()]);
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}