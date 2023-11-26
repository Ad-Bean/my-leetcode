#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
 public:
  vector<int> findWordsContaining(vector<string>& words, char x) {
    vector<int> ans;
    for (int i = 0; i < words.size(); i++) {
      for (int j = 0; j < words[i].size(); j++) {
        if (word[j] == x) {
          ans.emplace_back(i);
          break;
        }
      }
    }
    return ans;
  }
};

int main() {

  Solution test;
  return 0;
}