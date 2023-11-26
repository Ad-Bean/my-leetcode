class Solution {
 public:
  static const int N = 2e5 * 31;
  int idx = 0;
  int tr[N][2] = {0};

  Solution() {
    for (int i = 0; i <= idx; i++)
      tr[i][0] = tr[i][1] = 0;
    idx = 0;
  }

  void add(int x) {
    int p = 0;
    for (int i = 31; i >= 0; i--) {
      int u = (x >> i) & 1;
      if (tr[p][u] == 0) {
        tr[p][u] = ++idx;
      }
      p = tr[p][u];
    }
  }
  int getVal(int x) {
    int p = 0, ans = 0;
    for (int i = 31; i >= 0; i--) {
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
  int findMaximumXOR(vector<int>& nums) {
    int ans = 0;
    for (int i : nums) {
      add(i);
      int j = getVal(i);
      ans = max(ans, i ^ j);
    }
    return ans;
  }
};
