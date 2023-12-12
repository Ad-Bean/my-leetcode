#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个整数数组 nums，请你选择数组的两个不同下标 i 和 j，使 (nums[i]-1)*(nums[j]-1) 取得最大值。

请你计算并返回该式的最大值。
2 <= nums.length <= 500

方法一：On2 遍历

方法二：Onlgn 排序找最大

方法三：On 找最大和次大
擂台法
 */
class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int maxx = nums[0], maxx_sec = nums[1];
    if (maxx < maxx_sec) {
      swap(maxx, maxx_sec);
    }
    int n = nums.size();
    for (int i = 2; i < n; i++) {
      if (nums[i] > maxx) {
        maxx_sec = maxx;
        maxx = nums[i];
      } else if (nums[i] > maxx_sec) {
        maxx_sec = nums[i];
      }
    }
    return (maxx - 1) * (maxx_sec - 1);
  }
};
int main() {

  Solution test;
  return 0;
}
