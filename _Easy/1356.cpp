#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution {
  int countOne(int num) {
    int cnt = 0;
    while (num > 0) {
      num &= (num - 1);
      cnt++;
    }
    return cnt;
  }

 public:
  vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), [&](int a, int b) {
      int cnta = countOne(a), cntb = countOne(b);
      if (cnta == cntb) {
        return a < b;
      }
      return cnta < cntb;
    });
    return arr;
  }
};
int main() {

  Solution test;
  return 0;
}