
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个下标从 0 开始的整数数组 nums 和一个整数 k 。

请你用整数形式返回 nums 中的特定元素之 和 ，这些特定元素满足：其对应下标的二进制表示中恰存在 k 个置位。

整数的二进制表示中的 1 就是这个整数的 置位 。

例如，21 的二进制表示为 10101 ，其中有 3 个置位。

输入：nums = [5,10,1,5,2], k = 1
输出：13
解释：下标的二进制表示是： 
0 = 000
1 = 001
2 = 010
3 = 011
4 = 100
下标 1、2 和 4 在其二进制表示中都存在 k = 1 个置位。
因此，答案为 nums[1] + nums[2] + nums[4] = 13 。

1 <= nums[i] <= 10^5


方法一：内置函数 / 位运算

x = x&(x-1)

 */
class Solution {
 public:
  int countBit(int x) {
    int cnt = 0;
    while (x) {
      x = x & (x - 1);
      cnt++;
    }
    return cnt;
  }

  int sumIndicesWithKSetBits(vector<int>& nums, int k) {
    int sum = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      cout << nums[i] << " " << countBit(i) << endl;
      if (countBit(i) == k) {
        sum += nums[i];
      }
    }
    return sum;
  }
};
int main() {

  Solution test;
  vector<int> nums = {5, 10, 1, 5, 2};
  int k = 1;
  cout << test.sumIndicesWithKSetBits(nums, k) << endl;
  return 0;
}