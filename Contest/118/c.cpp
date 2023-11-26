#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 

*/

class Solution {
 public:
  int minimumCoins(vector<int>& prices) {
    int n = prices.size();
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
      dp[i] = dp[i - 1] + prices[i - 1];
      for (int j = i - 1; j >= 1; --j) {
        dp[i] = min(dp[i], dp[j - 1] + prices[j - 1]);
      }
    }

    return dp[n];
  }
};

int main() {
  Solution solution;
  vector<int> prices1 = {3, 1, 2};
  vector<int> prices2 = {1, 10, 1, 1};

  cout << "Result 1: " << solution.minimumCoins(prices1) << endl;
  cout << "Result 2: " << solution.minimumCoins(prices2) << endl;

  return 0;
}
