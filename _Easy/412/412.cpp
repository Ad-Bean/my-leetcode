#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        for(int i = 0;i < n;i++) ans[i] = to_string(i+1);
        for(int i = 3;i <= n; i+=3) ans[i-1] = "Fizz";
        for(int i = 5;i <= n; i+=5) ans[i-1] = "Buzz";
        for(int i = 15;i <= n;i+=15) ans[i-1] = "FizzBuzz";
        return ans;
    }
};
 */
class Solution {
 public:
  vector<string> fizzBuzz(int n) {
    vector<string> ans;
    for (int i = 1; i <= n; i++) {
      if ((i % 3 == 0) && (i % 5 == 0)) {
        ans.emplace_back("FizzBuzz");
      } else if (i % 3 == 0) {
        ans.emplace_back("Fizz");
      } else if (i % 5 == 0) {
        ans.emplace_back("Buzz");
      } else {
        ans.emplace_back(to_string(i));
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}
