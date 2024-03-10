#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
Given two integer arrays nums1 and nums2, 
sorted in non-decreasing order, 
return the minimum integer common to both arrays. 
If there is no common integer amongst nums1 and nums2, return -1.

Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.

 */
class Solution {
 public:
  int getCommon(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    int l = 0, r = 0;
    while (l < n && r < m) {
      if (nums1[l] == nums2[r]) {
        return nums1[l];
      } else if (nums1[l] < nums2[r]) {
        l++;
      } else {
        r++;
      }
    }
    return -1;
  }
};
int main() {

  Solution test;
  return 0;
}
