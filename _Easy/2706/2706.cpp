#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution {
 public:
  int buyChoco(vector<int>& prices, int money) {
    int minn = min(prices[0], prices[1]), minnn = max(prices[0], prices[1]);
    int n = prices.size();
    for (int i = 2; i < n; i++) {
      if (prices[i] < minn) {
        minnn = minn;
        minn = prices[i];
      } else if (prices[i] < minnn) {
        minnn = prices[i];
      }
    }
    int sum = minn + minnn;
    return sum <= money ? money - sum : money;
  }
};
int main() {

  Solution test;
  return 0;
}
