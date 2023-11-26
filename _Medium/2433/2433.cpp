#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
A ^ B = C -> A ^ C = B


arr[0] = pref[0]
arr[0] ^ arr[1] = pref[1] -> arr[0] ^ pref[1] = arr[1]
arr[0] ^ arr[1] ^ arr[2] = pref[2] -> arr[0] ^ arr[1] ^ pref[2] = arr[2] -> pref[1] ^ pref[2] = arr[2]

 */
class Solution {
 public:
  vector<int> findArray(vector<int>& pref) {
    vector<int> result(pref.size());
    result[0] = pref[0];
    for (int i = 1; i < pref.size(); i++) {
      result[i] = pref[i] ^ pref[i - 1];
    }
    return result;
  }
};
int main() {

  Solution test;
  return 0;
}