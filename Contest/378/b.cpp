#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
出现至少三次
a 长度一
aa 长度二

对每个位置枚举
abcaba

 */
class Solution {
 public:
  int maximumLength(string s) {
    int n = s.size();
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) {
      string t = "";
      for (int j = i; j < n; j++) {
        if (s[j] != s[i]) {
          break;
        }
        t += s[j];
        mp[t]++;
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
}