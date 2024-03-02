#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
Given an integer array nums sorted in non-decreasing order, 
return an array of the squares of each number sorted in non-decreasing order.

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

1 <= nums.length <= 1e4
方法一：模拟 + 排序
时间复杂度 O(nlogn)
方法二：
由于负数的平方一定是正数，且绝对值越大，平方值越大
所以可以使用双指针，从两端开始遍历，每次取绝对值较大的那个数的平方
时间复杂度 O(n)

 */

class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = n - 1;
    vector<int> ans(n);
    int end = n - 1;
    while (l <= r) {
      if (abs(nums[l]) > abs(nums[r])) {
        ans[end--] = nums[l] * nums[l];
        l++;
      } else {
        ans[end--] = nums[r] * nums[r];
        r--;
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  vector<int> nums = {-4, -1, 0, 3, 10};
  auto res = test.sortedSquares(nums);
  for (const auto i : res) {
    cout << i << " ";
  }
  return 0;
}
