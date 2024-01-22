
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

/* 
You have a set of integers s, which originally contains all the numbers from 1 to n. 
Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, 
which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

方法一：去重 + 排序  Ologn Ologn
注意处理 0 和 n
cur - pre > 1 的就是漏掉的

方法二：哈希 On On
计数后，从 1 到 n 开始遍历

方法三：位运算 + 分组亦或 On O1
重复的出现两次，未出现的出现 0 次
xor(nums[i]) ^ [1 .. n] = 未出现的数 ^ 重复的数 = xor

lowbit = xor & (-xor) 找到最低位 (-xor) 补码
比如 0010 -> 2, 1110 -> -2 (取反+1, 1101+1=1110)  0010 & 1110 = 0010 找到了最低位

此时 x^y 的最低位表示，在这位：未出现的数 和 重复的数 不同
将该位为 0 的分为一组，该位为 1 的分为一组
两组中 x 只出现一次，y 只出现一次


 */
class Solution {
 public:
  vector<int> findErrorNums(vector<int>& nums) {
    int dif = 0, n = nums.size();
    for (int i = 1; i <= n; i++) {
      dif ^= nums[i - 1];
      dif ^= i;
    }
    int lowbit = dif & (-dif);  // 求最低的 1 位
    int num1 = 0, num2 = 0;
    for (int i = 1; i <= n; i++) {
      if ((i & lowbit) == 0) {
        num1 ^= i;
      } else {
        num2 ^= i;
      }
      if ((lowbit & nums[i - 1]) == 0) {
        num1 ^= nums[i - 1];
      } else {
        num2 ^= nums[i - 1];
      }
    }
    for (const int& num : nums) {
      if (num == num1) {
        return {num1, num2};  // 重复
      }
    }
    return {num2, num1};
  }
};
int main() {

  Solution test;
  vector<int> t = {1, 2, 2, 4};
  auto ans = test.findErrorNums(t);
  cout << ans[0] << "   " << ans[1] << endl;
  return 0;
}