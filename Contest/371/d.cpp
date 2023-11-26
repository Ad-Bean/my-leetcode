#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
|x - y|
y - x <= x
y <= 2 * x


1 2 3 4 5

1 

 */
class Solution {
 public:
  static const int MAX = 20;
  static const int N = 5e4 * MAX;
  int idx = 0;
  int tr[N][2] = {0};
  int sz[N];

  Solution() {
    for (int i = 0; i <= idx; i++)
      tr[i][0] = tr[i][1] = 0;
    idx = 0;
  }

  void add(int x) {
    int p = 0;
    for (int i = MAX; i >= 0; i--) {
      int u = (x >> i) & 1;
      if (tr[p][u] == 0) {
        tr[p][u] = ++idx;
        sz[idx] = 0;
      }
      p = tr[p][u];
      sz[p]++;
    }
  }
  void remove(int x) {
    int p = 0;
    for (int i = 20; i >= 0; --i) {
      int u = (x >> i) & 1;
      p = tr[p][u];
      sz[p]--;
    }
  }

  int getVal(int x) {
    int p = 0, ans = 0;
    for (int i = MAX; i >= 0; i--) {
      int a = (x >> i) & 1;
      int b = 1 - a;
      if (tr[p][b] != 0) {
        ans |= (b << i);
        p = tr[p][b];
      } else {
        ans |= (a << i);
        p = tr[p][a];
      }
    }
    return ans;
  }

  int maximumStrongPairXor(vector<int>& nums) {
    int ans = 0;
    sort(nums.begin(), nums.end());
    int l = 0, n = nums.size();
    for (int r = 0; r < n; r++) {
      add(nums[r]);
      while (2 * nums[l] < nums[r]) {
        remove(nums[l]);
        l++;
      }
      ans = max(ans, getVal(nums[r]));
    }
    return ans;
  }
};

int main() {

  Solution test;
  vector<int> ans{500, 520, 2500, 3000};
  cout << test.maximumStrongPairXor(ans) << endl;
  return 0;
}