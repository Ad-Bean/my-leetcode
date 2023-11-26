#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
 public:
  int findTheLongestBalancedSubstring(string s) {
    int ans = 0;
    int cur = 0, pre = 0;
    for (int i = 0; i < s.size(); i++) {
      cur++;
      if (i == s.size() - 1 || s[i] != s[i + 1]) {
        if (s[i] == '1') {
          ans = max(ans, min(pre, cur) * 2);
        }
        pre = cur;
        cur = 0;
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}