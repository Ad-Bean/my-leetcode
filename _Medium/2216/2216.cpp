#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
 public:
  int minDeletion(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    bool check = true;
    for (int i = 0; i < n - 1; i++) {
      if (nums[i] == nums[i + 1] && check) {
        ++ans;
      } else {
        check = !check;
      }
    }
    if ((n - ans) % 2 != 0) {
      ++ans;
    }
    return ans;
  }
};

int main() {

  Solution test;
  return 0;
}