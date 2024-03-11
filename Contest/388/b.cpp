#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

class Solution {
  typedef long long ll;

 public:
  long long maximumHappinessSum(vector<int>& happiness, int k) {
    int n = happiness.size();
    sort(happiness.begin(), happiness.end(), greater<int>());
    ll ans = 0;
    for (int i = 0; i < k; i++) {
      ans += max(0, happiness[i] - i);
    }
    return ans;
  }
};
int main() {

  Solution test;
  vector<int> a = {12, 1, 42};
  int k = 3;
  cout << test.maximumHappinessSum(a, k);
  return 0;
}
/* 
42
11

 */