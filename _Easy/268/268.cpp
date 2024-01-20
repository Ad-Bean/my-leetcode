#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。


方法一：排序
排序后比较 i == nums[i]

方法二：哈希
mp[nums[i]]++
检查 0 到 i 是否在哈希

方法三：位运算
nums 中有 n 个数，添加 [0,n], 对所有数字进行亦或
最后出现的数字就是丢失的数字

方法四：数学
0 到 n 之和为 n(n+1)/2
求出 nums[i] 的和，由于 arrSum 少 n(n+1)/2 一个数，差即该数字

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        return n * (n + 1) / 2 - accumulate(nums.begin(), nums.end(), 0);
    }
};
*/

class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans ^= nums[i];
      ans ^= i;
    }
    ans ^= n;
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}
