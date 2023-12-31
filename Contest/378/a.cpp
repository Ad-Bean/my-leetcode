#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
class Solution {
 public:
  bool hasTrailingZeros(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (!((nums[i] | nums[j]) & 1)) {
          return true;
        }
      }
    }
    return false;
  }
};
int main() {

  Solution test;
  return 0;
}