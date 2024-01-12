#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你两个字符串数组 words1 和 words2 ，请你返回在两个字符串数组中 都恰好出现一次 的字符串的数目。

 */
class Solution {
 public:
  int countWords(vector<string>& words1, vector<string>& words2) {
    unordered_map<string, int> mp1;
    unordered_map<string, int> mp2;
    for (const string& word : words1) {
      mp1[word]++;
    }
    for (const string& word : words2) {
      mp2[word]++;
    }
    int cnt = 0;
    for (const auto [k, v] : mp1) {
      if (v == 1 && mp2[k] == 1) {
        cnt++;
      }
    }
    return cnt;
  }
};
int main() {

  Solution test;
  return 0;
}
