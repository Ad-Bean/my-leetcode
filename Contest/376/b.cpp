#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
输入：nums = [1,3,4,8,7,9,3,5,1], k = 2
输出：[[1,1,3],[3,4,5],[7,8,9]]


输入：nums = [1,3,3,2,7,3], k = 3
输出：[]
1 2 3 3 3 7
 */
class Solution {
 public:
  vector<vector<int>> divideArray(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans(n / 3);
    for (int i = 0; i < n; i++) {
      ans[i / 3].emplace_back(nums[i]);
      if ((i + 1) % 3 == 0) {
        if (ans[i / 3].back() - ans[i / 3][0] > k) {
          return vector<vector<int>>();
        }
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}