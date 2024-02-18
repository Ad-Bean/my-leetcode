#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
class Solution {
  bool isPrime(int x) {
    if (x < 2) {
      return false;
    }
    for (int i = 2; i * i <= x; i++) {
      if (x % i == 0) {
        return false;
      }
    }
    return true;
  }

 public:
  int mostFrequentPrime(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    unordered_map<int, int> cnt;
    const int dirs[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        for (const auto dir : dirs) {
          int x = i + dir[0], y = j + dir[1];
          string s = to_string(mat[i][j]);
          while (x >= 0 && x < m && y >= 0 && y < n) {
            s += to_string(mat[x][y]);
            int num = stoi(s);
            if (num > 10 && isPrime(num)) {
              cnt[num]++;
            }
            x += dir[0];
            y += dir[1];
          }
        }
      }
    }
    if (cnt.empty()) {
      return -1;
    }
    int ans = 0, maxcnt = -1;
    for (const auto& [p, c] : cnt) {
      if (c > maxcnt) {
        maxcnt = c;
        ans = p;
      } else if (c == maxcnt) {
        ans = max(ans, p);
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  vector<vector<int>> mat = {
      {7},
  };
  cout << test.mostFrequentPrime(mat) << endl;
  return 0;
}