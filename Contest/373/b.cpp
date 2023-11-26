#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
 public:
  int beautifulSubstrings(string s, int k) {
    int ans = 0;
    int n = s.size();
    unordered_map<char, bool> vowel{
        {'a', true}, {'e', true}, {'i', true}, {'o', true}, {'u', true},
    };
    for (int i = 0; i < n; i++) {
      int vow = 0;
      for (int j = i; j < n; j++) {
        if (vowel[s[j]]) {
          vow++;
        }
        if ((j - i + 1) - vow == vow && (vow * vow) % k == 0) {
          ans++;
        }
      }
    }
    return ans;
  }
};

int main() {

  Solution test;
  return 0;
}