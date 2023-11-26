#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
 public:
  int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    if (arr[0] != 1) {
      arr[0] = 1;
    }
    for (int i = 1; i < n; i++) {
      if (arr[i] - arr[i - 1] > 1) {
        arr[i] = arr[i - 1];
      }
    }
    return arr[n - 1];
  }
};
int main() {

  Solution test;
  return 0;
}