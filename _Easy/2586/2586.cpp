#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
 public:
  int vowelStrings(vector<string>& words, int left, int right) {
    int n = words.size();
    unordered_map<char, int> mp{
        {'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1},
    };
    int ans = 0;
    for (int i = left; i <= right; ++i) {
      string word = words[i];
      if (mp[word[0]] == 1 && mp[word[word.size() - 1]] == 1) {
        ans++;
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}