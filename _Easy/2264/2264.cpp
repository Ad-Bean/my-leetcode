
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string res;
        for (int i = 0; i < n - 2; ++i) {
            if (num[i] == num[i+1] && num[i+1] == num[i+2]) {
                res = max(res, num.substr(i, 3));
            }
        }
        return res;
    }
};
*/
class Solution {
 public:
  string largestGoodInteger(string num) {
    int n = num.size();
    int max_num = -1;
    string ans = "";
    for (int l = 0, r = 1; r < n && l < n; r++) {
      if (num[r] != num[l]) {
        l = r;
      }
      if (r - l + 1 == 3) {
        int cur = num[l] - '0';
        int numm = cur * 100 + cur * 10 + cur;
        if (numm > max_num) {
          max_num = numm;
          ans = to_string(num[l]) + to_string(num[l]) + to_string(num[l]);
        }
        l++;
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  string num = "6777133333333333339";
  cout << test.largestGoodInteger(num) << endl;
  return 0;
}