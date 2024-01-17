#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
Given an array of integers arr, 
return true if the number of occurrences of each value in the array is unique or false otherwise.

方法一：哈希
 */
class Solution {
 public:
  bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> mp;
    for (const int& a : arr) {
      mp[a]++;
    }
    unordered_set<int> cnt;
    for (const auto& [k, v] : mp) {
      if (cnt.count(v)) {
        return false;
      }
      cnt.insert(v);
    }
    return true;  // 或者返回 cnt.size() == mp.size();
  }
};
int main() {

  Solution test;
  return 0;
}
