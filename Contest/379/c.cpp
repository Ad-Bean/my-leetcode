#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution {
 public:
  int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
    set<int> st1, st2;
    int n = nums1.size();
    for (int i = 0; i < n; i++) {
      st1.emplace(nums1[i]);
      st2.emplace(nums2[i]);
    }
    // 剩下多少不同的
    int s1 = max(int(st1.size()) - n / 2, 0);
    int s2 = max(int(st2.size()) - n / 2, 0);
    set<int> st;
    for (const auto num : st1) {
      if (!s1) {
        st.emplace(num);
        continue;
      }
      if (st2.find(num) != st2.end()) {
        s1--;
      } else {
        st.emplace(num);
      }
    }
    for (const auto num : st2) {
      if (!s2) {
        st.emplace(num);
        continue;
      }
      if (st.find(num) != st.end()) {
        s2--;
      } else {
        st.emplace(num);
      }
    }
    return st.size() - s1 - s2;
  }
};
int main() {

  Solution test;
  return 0;
}