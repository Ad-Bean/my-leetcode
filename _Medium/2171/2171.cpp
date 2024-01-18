#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

/* 

给定一个 正整数 数组 beans ，其中每个整数表示一个袋子里装的魔法豆的数目。

请你从每个袋子中 拿出 一些豆子（也可以 不拿出），使得剩下的 非空 袋子中（即 至少还有一颗 魔法豆的袋子）魔法豆的数目 相等。
一旦把魔法豆从袋子中取出，你不能再将它放到任何袋子中。

请返回你需要拿出魔法豆的 最少数目。

方法一：排序
找一个数量，清空比它小的，另比它大的和它一样
暴力的方法是，对每个数都这么尝试一下，即 
for i in range (n): 
    cost = 0
    for j in range (n):
        if i == j: 
            continue
        if nums[i] > nums[j]:
            cost += nums[j]
        else:
            cost += nums[j] - nums[i]

但此时时间复杂度 O(n^2) 会超时
由于会涉及到大小判断和 nums[j] - nums[i]，尝试使用排序
这样对每个 nums[i]，左边的全部小于它，右边的全部大于它
于是它的代价就是 sum(nums[:i]) + sum(nums[i:] - nums[i]) = sum(nums) - nums[i] * (n-i)

 */
class Solution {
  typedef long long ll;

 public:
  long long minimumRemoval(vector<int>& beans) {
    sort(beans.begin(), beans.end());
    int n = beans.size();
    ll sum = accumulate(beans.begin(), beans.end(), 0LL);
    ll res = sum;
    for (int i = 0; i < n; i++) {
      res = min(res, sum - beans[i] * (n - i) * 1LL);
    }
    return res;
  }
};
int main() {

  Solution test;
  return 0;
}
