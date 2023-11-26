#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
max + max + 1 + ... + max + k-1

k * max + (0 + k - 1)*k / 2


5 * 3 + 3 * 2 / 2 = 18
 */
class Solution {
 public:
  int maximizeSum(vector<int>& nums, int k) {
    int maxNum = *max_element(nums.begin(), nums.end());
    return k * maxNum + (k - 1) * k / 2;
  }
};
int main() {

  Solution test;
  return 0;
}