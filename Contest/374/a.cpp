#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution {
 public:
  vector<int> findPeaks(vector<int>& mountain) {
    int n = mountain.size();
    vector<int> ans;
    for (int i = 1; i < n - 1; i++) {
      if ((mountain[i] > mountain[i - 1]) && (mountain[i] > mountain[i + 1])) {
        ans.emplace_back(i);
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}