#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int l = m - 1, r = n - 1;
    int tail = m + n - 1;
    while (l >= 0 || r >= 0) {
      int cur = -1;
      if (l == -1) {
        cur = nums2[r--]
      } else if (r == -1) {
        cur = nums1[l--];
      } else if (nums1[l] < nums2[r]) {
        cur = nums2[r--]
      } else {
        cur = nums1[l--]
      }
      nums1[tail--] = cur;
    }
  }
};
int main() {

  Solution test;
  return 0;
}