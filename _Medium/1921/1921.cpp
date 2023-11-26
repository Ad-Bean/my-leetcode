#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
 public:
  int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    int n = dist.size();
    vector<int> att(n);
    for (int i = 0; i < n; i++) {
      att[i] = (dist[i]) / speed[i] + 1;
    }
    sort(att.begin(), att.end());
    for (int i = 0; i < n; i++) {
      if (att[i] <= i) {
        return i;
      }
    }
    return n;
  }
};
int main() {

  Solution test;
  return 0;
}