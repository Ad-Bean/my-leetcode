#include <bits/stdc++.h>
using namespace std;
/* 
aaaaaaa
aaaaaaaaaaaaaab
aaaaabbbbbbbb

 */
typedef long long ll;
class Solution {
 public:
  int findMinimumOperations(string s1, string s2, string s3) {
    int i = 0, j = 0, k = 0;
    while (i < s1.length() && j < s2.length() && k < s3.length()) {
      if (s1[i] == s2[j] && s2[j] == s3[k]) {
        i++;
        j++;
        k++;
      } else {
        if (i == 0) {
          return -1;
        } else {
          return s1.length() - i + s2.length() - i + s3.length() - i;
        }
      }
    }
    int minn = min(s1.length(), s2.length());
    minn = min(minn, (int)s3.length());
    return s1.length() + s2.length() + s3.length() - minn - minn - minn;
  }
};
int main() {

  Solution test;
  return 0;
}