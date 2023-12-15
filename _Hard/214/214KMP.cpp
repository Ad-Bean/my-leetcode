#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution {
 public:
  string shortestPalindrome(string s) {
    int n = s.size();
    vector<int> next(n, -1);
    for (int i = 1; i < n; i++) {
      int j = next[i - 1];
      while (j != -1 && s[j + 1] != s[i]) {
        j = next[j];
      }
      if (s[j + 1] == s[i]) {
        next[i] = j + 1;
      }
    }
    int j = -1;
    for (int i = n - 1; i >= 0; i--) {
      while (j != -1 && s[j + 1] != s[i]) {
        j = next[j];
      }
      if (s[j + 1] == s[i]) {
        ++j;
      }
    }
    string s_ = (j == n - 1) ? "" : s.substr(j + 1);
    reverse(s_.begin(), s_.end());
    return s_ + s;
  }
};
int main() {

  Solution test;
  return 0;
}