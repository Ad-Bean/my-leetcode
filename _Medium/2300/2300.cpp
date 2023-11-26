#include <bits/stdc++.h>
using namespace std;
/* 
5 1 3
1 2 3 4 5
success = 7
对 5，二分 7 / 5 + 1 = 2，存在下标 1，返回 5 - 1 = 4
对 1，二分 7 / 1  = 7，不存在下标，则 0
对 3，二分 7 / 3 + 1 = 3，存在下标 2，返回 5 - 2 = 3

lower_bound(potions.begin(), potions.end(), t) - potions.begin() 是下标

lower_bound 是第一个大于等于
upper_bound 是第一个大于

ceil(A / B) = (A + B - 1) / spell - 1
由于 A>1、B>1，且 A、B 都是整数，所以可以设 A=NB+M，其中 N 为非负整数，M 为 0 到 B-1 的数，则
A/B = N + M/B
(A+B-1)/B = N + 1 + (M - 1)/B;
当M为0时，UP(A/B) = N，
int((A+B-1)/B) = N + int(1 - 1/B) = N

当 M 为 1 到 B-1 的数时，0 <= M-1 <= B-2
UP(A/B) = N + 1，
int((A+B-1)/B) = N + 1 + int((M-1)/B) = N + 1
所以对A>1、B>1的整数A、B都有：
UP(A/B) = int((A+B-1)/B)


 */
typedef long long ll;
class Solution {
 public:
  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    sort(potions.begin(), potions.end());
    int n = potions.size();
    vector<int> ans;
    for (const int& spell : spells) {
      //   ll target = ceil(success * 1.0 / spell);
      ll target = (success + spell - 1) / spell;
      int l = 0, r = n - 1;
      while (l <= r) {
        int m = l + (r - l) / 2;
        if (potions[m] >= target) {
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
      // l 第一个大于等于
      ans.emplace_back(n - l);
    }
    /* 
    for (auto& spell : spells) {
        long long t = (success + spell - 1) / spell - 1; 
        res.push_back(potions.size() - (upper_bound(potions.begin(), potions.end(), t) - potions.begin()));
    }
    sort(potions.begin(), potions.end());
    vector<int> res;
    return res;
     */
    return ans;
  }
};

int main() {

  Solution test;
  //   vector<int> spells{5, 1, 3};
  //   vector<int> potions{1, 2, 3, 4, 5};
  //   ll success = 7;
  vector<int> spells{3, 1, 2};
  vector<int> potions{5, 8, 8};
  ll success = 16;
  vector<int> ans = test.successfulPairs(spells, potions, success);
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}