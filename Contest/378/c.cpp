#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution {
 public:
  int maximumLength(string s) {
    int n = s.size();
    int l = 0;
    unordered_map<string, int> mp;
    for (int r = 0; r < n; r++) {
      if (s[l] != s[r]) {
        int sz = r - l;
        int i = 1;
        while (i <= 3 && sz > 0) {
          mp[string(sz, s[l])] += i;
          i++;
          sz--;
        }
        l = r;
      }
    }
    if (s[n - 1] == s[l]) {
      int sz = n - 1 - l + 1;
      int i = 1;
      while (i <= 3 && sz > 0) {
        mp[string(sz, s[l])] += i;
        i++;
        sz--;
      }
    }

    int maxx = -1;
    for (const auto& [k, v] : mp) {
      if (v >= 3) {
        maxx = max(maxx, int(k.size()));
      }
    }
    return maxx;
  }
};
int main() {

  Solution test;
  string s = "abcccccdddd";
  cout << test.maximumLength(s) << endl;
  return 0;
  return 0;
}