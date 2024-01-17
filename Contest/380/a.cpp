#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个由 正整数 组成的数组 nums 。

返回数组 nums 中所有具有 最大 频率的元素的 总频率 。

元素的 频率 是指该元素在数组中出现的次数。


方法一：两次遍历
方法二：一次遍历
 */
class Solution {
 public:
  int maxFrequencyElements(vector<int>& nums) {
    unordered_map<int, int> cnt;
    int maxx = 0;
    for (const auto& num : nums) {
      cnt[num]++;
      maxx = max(cnt[num], maxx);
    }
    int sum = 0;
    for (const auto& [k, v] : cnt) {
      if (v == maxx) {
        sum += v;
      }
    }
    return sum;
  }
};
int main() {

  Solution test;
  return 0;
}