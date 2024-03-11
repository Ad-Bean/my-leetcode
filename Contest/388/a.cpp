#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution {
 public:
  int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
    sort(capacity.begin(), capacity.end(), [&](int a, int b) { return a > b; });
    int n = apple.size();
    int total = accumulate(apple.begin(), apple.end(), 0);
    int cnt = 0;

    for (int i = 0; i < capacity.size(); i++) {
      total -= capacity[i];
      cnt++;
      if (total <= 0) {
        return cnt;
      }
    }
    return capacity.size();
  }
};

int main() {

  Solution test;
  vector<int> a = {6};
  vector<int> b = {5, 5, 1};
  cout << test.minimumBoxes(a, b);
  return 0;
}