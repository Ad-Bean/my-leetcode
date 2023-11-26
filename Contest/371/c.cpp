#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
1,2,7
4,5,3



 
 */
class Solution {
 public:
  int minOperations(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int last = n - 1;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < last; i++) {
      if (nums1[i] > nums1[last] || nums2[i] > nums2[last]) {
        if (nums1[i] > nums2[last] || nums2[i] > nums1[last]) {
          return -1;
        }
        cnt1++;
      }
    }
    swap(nums1[last], nums2[last]);
    cnt2 = 1;
    for (int i = 0; i < last; i++) {
      if (nums1[i] > nums1[last] || nums2[i] > nums2[last]) {
        if (nums1[i] > nums2[last] || nums2[i] > nums1[last]) {
          return -1;
        }
        cnt2++;
      }
    }
    return min(cnt1, cnt2);
  }
};

int main() {

  Solution test;
  return 0;
}