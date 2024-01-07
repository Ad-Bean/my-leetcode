#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution {
 public:
  int minOperations(vector<int>& nums, int k) {
    int sum = 0;
    for (const int& num : nums) {
      sum ^= num;
    }
    int ans = 0;
    while (k || sum) {
      if ((k & 1) != (sum & 1)) {
        ans++;
      }
      k >>= 1;
      sum >>= 1;
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}