#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 

给你一个下标从 0 开始的整数数组 nums ，数组长度为 偶数 ，由数目相等的正整数和负整数组成。

你需要 重排 nums 中的元素，使修改后的数组满足下述条件：

任意 连续 的两个整数 符号相反
对于符号相同的所有整数，保留 它们在 nums 中的 顺序 。
重排后数组以正整数开头。
重排元素满足上述条件后，返回修改后的数组。

输入：nums = [3,1,-2,-5,2,-4]
输出：[3,-2,1,-5,2,-4]
解释：
nums 中的正整数是 [3,1,2] ，负整数是 [-2,-5,-4] 。
重排的唯一可行方案是 [3,-2,1,-5,2,-4]，能满足所有条件。

暴力：分组
用两个数组存储正数、负数

方法一：双指针
int n = nums.size();
int pos = 0, neg = 0;
vector<int> ans;
for (int i = 0; i + i < n; ++i) {
    while (nums[pos] < 0) {     // pos 正数
        ++pos;
    }
    ans.push_back(nums[pos]);
    ++pos; 
    while (nums[neg] > 0) {    // neg 负数
        ++neg;
    }
    ans.push_back(nums[neg]);
    ++neg;
}
return ans;

 */
class Solution {
 public:
  vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> n, p;
    for (const auto& num : nums) {
      if (num < 0) {
        n.emplace_back(num);
      } else {
        p.emplace_back(num);
      }
    }
    vector<int> ans;
    int i = 0;
    int len = nums.size() / 2;
    while (i < len) {
      ans.emplace_back(p[i]);
      ans.emplace_back(n[i]);
      i++;
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}
