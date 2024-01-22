#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

/* 
给定一个非负整数，你至多可以交换一次数字中的任意两位。返回你能得到的最大值。

输入: 2736
输出: 7236
解释: 交换数字2和数字7。

方法一：遍历 O((log num)^3)
[0, 1e8] 一共八位，C8,2 = 7 * 8 / 2 = 28 种交换方法
遍历这些方法

方法二：贪心 
让低位大数 与 高位小数 进行交换

从低位遍历，记录最大值的索引 max_idx
如果当前 num[i] < num[max_idx] 尝试交换，记录更大值
 */

class Solution {
 public:
  int maximumSwap(int num) {
    int ans = num;
    string nums = to_string(num);
    int n = nums.size();
    int max_idx = n - 1;
    for (int i = n - 1; i >= 0; i--) {
      if (nums[i] > nums[max_idx]) {
        max_idx = i;
      } else if (nums[i] < nums[max_idx]) {
        swap(nums[i], nums[max_idx]);
        ans = max(ans, stoi(nums));
        swap(nums[i], nums[max_idx]);
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}
