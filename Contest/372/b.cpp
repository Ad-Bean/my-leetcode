#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
 public:
  long long minimumSteps(string s) {
    int n = s.length();
    int blackCount = 0;
    long long steps = 0;

    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        blackCount++;
      } else {
        steps += blackCount;
      }
    }

    return steps;
  }
};
int main() {

  Solution test;
  cout << test.minimumSteps("101") << endl;          // 输出：1
  cout << test.minimumSteps("10000000100") << endl;  // 输出：2
  cout << test.minimumSteps("0111") << endl;         // 输出：0

  return 0;
}