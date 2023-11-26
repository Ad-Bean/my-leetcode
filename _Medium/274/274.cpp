#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int l = 1, r = citations.size();
    int mid = 0, cnt = 0;
    while (l <= r) {
      mid = l + (r - l) / 2;
      for (int i = 0; i < citations.size(); i++) {
        cnt = 0;
        if (citations[i] >= mid) {
          cnt++;
        }
      }
      if (mid <= cnt) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return r;
  }
};

int main() {

  Solution test;
  return 0;
}