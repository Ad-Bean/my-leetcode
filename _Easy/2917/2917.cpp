#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个下标从 0 开始的整数数组 nums 和一个整数 k 。

nums 中的 K-or 是一个满足以下条件的非负整数：

只有在 nums 中，至少存在 k 个元素的第 i 位值为 1 ，那么 K-or 中的第 i 位的值才是 1 。
返回 nums 的 K-or 值。

注意 ：对于整数 x ，如果 (2i AND x) == 2i ，则 x 中的第 i 位值为 1 ，其中 AND 为按位与运算符。

方法一：枚举 + 位计算
枚举 i \in [0, 31]，对每个数查看 i 是否为一并且计数

 */
class Solution {
 public:
  int findKOr(vector<int>& nums, int k) {
    int n = nums.size();

    int ans = 0;
    for (int i = 0; i < 32; i++) {
      int cnt = 0;
      for (int j = 0; j < n; j++) {
        if (nums[j] & (1 << i)) {
          cnt++;
        }
      }
      if (cnt >= k) {
        ans += (1 << i);
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}
