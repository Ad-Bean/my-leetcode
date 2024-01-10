#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个下标从 0 开始的整数数组 nums 和一个正整数 k 。

你可以对数组执行以下操作 任意次 ：

选择数组里的 任意 一个元素，并将它的 二进制 表示 翻转 一个数位，翻转数位表示将 0 变成 1 或者将 1 变成 0 。
你的目标是让数组里 所有 元素的**按位异或和**得到 k ，请你返回达成这一目标的 最少 操作次数。

注意，你也可以将一个数的前导 0 翻转。比方说，数字 (101)2 翻转第四个数位，得到 (1101)2 。

输入：nums = [2,1,3,4], k = 1
输出：2
解释：我们可以执行以下操作：
- 选择下标为 2 的元素，也就是 3 == (011)2 ，我们翻转第一个数位得到 (010)2 == 2 。数组变为 [2,1,2,4] 。
- 选择下标为 0 的元素，也就是 2 == (010)2 ，我们翻转第三个数位得到 (110)2 == 6 。数组变为 [6,1,2,4] 。
最终数组的所有元素异或和为 (6 XOR 1 XOR 2 XOR 4) == 1 == k 。
无法用少于 2 次操作得到异或和等于 k 。
2,1,3,4

010
001
011
100
原数组亦或和 100
目标        001

方法一：内置函数 __builtin_popcount
先得到原数组的亦或和
数 原数组亦或和 ^ 目标 中的 1 的个数


 */
class Solution {
 public:
  int minOperations(vector<int>& nums, int k) {
    int sum = 0;
    for (const int& num : nums) {
      sum ^= num;
    }
    return __builtin_popcount(sum ^ k);
  }
};
int main() {

  Solution test;
  return 0;
}