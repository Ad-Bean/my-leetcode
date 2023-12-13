
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
从右到左
s[left] = s[right] = min(s[left], s[right]);

 */
class Solution {
 public:
  string makeSmallestPalindrome(string s) {
    int n = s.size();
    int l = 0, r = n - 1;
    string ans = s;
    while (l < r) {
      if (ans[l] != ans[r]) {
        if (ans[l] < ans[r]) {
          ans[r] = ans[l];
        } else {
          ans[l] = ans[r];
        }
      }
      l++, r--;
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}