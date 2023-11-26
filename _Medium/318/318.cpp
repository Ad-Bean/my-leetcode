#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
vector<vector<int>> mp(n, vector<int>(26));
for (int i = 0; i < n; i++) {
    for (const char& c : words[i]) {
    mp[i][c - 'a']++;
    }
}

只有 26 个小写字幕，进行二进制状态压缩

vector<int> mask(n)
for (int i = 0; i < n; i++) {

}

 */
class Solution {
 public:
  int maxProduct(vector<string>& words) {
    int ans = 0;
    int n = words.size();
    vector<int> masks(n);
    for (int i = 0; i < n; i++) {
      for (const char& c : words[i]) {
        masks[i] |= 1 << (c - 'a');
      }
    }

    for (int i = 0; i < n; i++) {
      int lena = words[i].size();
      for (int j = i + 1; j < n; j++) {
        int lenb = words[j].size();
        if ((masks[i] & masks[j]) == 0) {
          ans = max(ans, lena * lenb);
        }
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  vector<string> words{"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
  cout << test.maxProduct(words) << endl;
  return 0;
}