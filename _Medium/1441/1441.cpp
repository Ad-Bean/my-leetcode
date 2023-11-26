#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
 public:
  vector<string> buildArray(vector<int>& target, int n) {
    vector<string> ans;
    for (int i = 1, j = 0; i <= n && j < target.size(); i++) {
      ans.emplace_back("push");
      if (target[j] != i)
        ans.emplace_back("Pop");
      else
        j++;
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}