#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/* 
给你一个整数数组 arr 和一个整数 k 。现需要从数组中恰好移除 k 个元素，请找出移除后数组中不同整数的最少数目。

方法一：贪心
首先统计每个数字的出现次数，然后按照出现次数从小到大排序。接下来，我们可以使用贪心算法来解决这个问题。

*/

typedef pair<int, int> pii;
class Solution {
 public:
  int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    unordered_map<int, int> cnt;
    for (const int& x : arr) {
      cnt[x]++;
    }
    vector<pii> vec(cnt.begin(), cnt.end());
    sort(vec.begin(), vec.end(), [](const pii& a, const pii& b) { return a.second < b.second; });

    int ans = vec.size();
    for (auto [_, f] : vec) {
      if (k >= f) {
        k -= f;
        ans--;
      } else {
        break;
      }
    }
    return ans;
  }
};

int main() {

  Solution test;
  return 0;
}
