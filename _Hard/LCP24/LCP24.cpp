
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

/* 
小扣在秋日市集入口处发现了一个数字游戏。
主办方共有 N 个计数器，计数器编号为 0 ~ N-1。
每个计数器上分别显示了一个数字，小扣按计数器编号升序将所显示的数字记于数组 nums。
每个计数器上有两个按钮，分别可以实现将显示数字加一或减一。小扣每一次操作可以选择一个计数器，按下加一或减一按钮。

主办方请小扣回答出一个长度为 N 的数组，第 i 个元素(0 <= i < N)表示将 0~i 号计数器 初始 所示数字操作成满足所有条件 nums[a]+1 == nums[a+1],(0 <= a < i) 的最小操作数。回答正确方可进入秋日市集。

由于答案可能很大，请将每个最小操作数对 1,000,000,007 取余。

输入：nums = [3,4,5,1,6,7]
输出：[0,0,0,5,6,7]
解释： i = 0，[3] 无需操作 i = 1，[3,4] 无需操作； i = 2，[3,4,5] 无需操作； i = 3，将 [3,4,5,1] 操作成 [3,4,5,6], 最少 5 次操作； i = 4，将 [3,4,5,1,6] 操作成 [3,4,5,6,7], 最少 6 次操作； i = 5，将 [3,4,5,1,6,7] 操作成 [3,4,5,6,7,8]，最少 7 次操作； 返回 [0,0,0,5,6,7]。

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^3

方法一：贪心

假设最小值 x
则最小化 |nums[i] - x - i| = |nums[0] - x| + |nums[1] - 1 - x| + ...
假设数组 arr[i] = nums[i] - i
需要求一个值 x 使得 |arr[i] - x| 最小，这个数就是中位数
由于题目求的是到 i，所以需要动态维护中位数，需要用到堆
由于是需要中位数，可以考虑两个堆，维护较小的一半和较大的一半

为了求 ans[i] = sum(|nums[i] - i - x|)
             = |b0 - x| + |b1 - x| + |b2 - x| + |...|


 */
typedef long long ll;

class Solution {
 public:
  vector<int> numsGame(vector<int>& nums) {
    const int MOD = 1e9 + 7;
    int n = nums.size();
    vector<int> ans(n);
    priority_queue<int> l;                             // 大顶堆
    priority_queue<int, vector<int>, greater<int>> r;  // 小顶堆
    ll lSum = 0, rSum = 0;
    for (int i = 0; i < n; i++) {
      int num = nums[i] - i;
      if ((i & 1) == 0) {                   // 奇数长度
        if (!l.empty() && num < l.top()) {  // 大顶堆
          lSum -= l.top() - num;
          l.emplace(num);
          num = l.top();
          l.pop();
        }
        rSum += num;
        r.emplace(num);
        ans[i] = (rSum - r.top() - lSum) % MOD;
      } else {
        if (num > r.top()) {
          rSum += num - r.top();
          r.emplace(num);
          num = r.top();
          r.pop();
        }
        lSum += num;
        l.emplace(num);
        ans[i] = (rSum - lSum) % MOD;
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}
