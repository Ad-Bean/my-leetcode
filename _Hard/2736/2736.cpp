#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
nums1 nums2
按照下标合并成一个数组，

 */
class Solution {
 public:
  vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
    vector<pair<int, int>> nums;
    int n = nums1.size();
    for (int i = 0; i < n; i++) {
      nums.emplace_back(nums1[i], nums2[i]);
    }
    sort(nums.begin(), nums.end(), greater<pair<int, int>>());
    for (int i = 0; i < queries.size(); i++) {}
  }
};
int main() {

  Solution test;
  return 0;
}