#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
class Solution {
 public:
  int maximumLengthSubstring(string s) {
    int n = s.size();
    int cnt[26] = {0};
    int l = 0, ans = 0;
    for (int r = 0; r < n; r++) {
      cnt[s[r] - 'a']++;
      while (cnt[s[r] - 'a'] > 2) {
        cnt[s[l] - 'a']--;
        l++;
      }
      ans = max(ans, r - l + 1);
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}