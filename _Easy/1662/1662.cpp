
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
 public:
  bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    string a = "", b = "";
    for (const string& word : word1) {
      a += word;
    }
    for (const string& word : word2) {
      b += word;
    }
    return a == b;
  }

  bool arrayStringsAreEqualSpace(vector<string>& word1, vector<string>& word2) {
    int p1 = 0, p2 = 0, i = 0, j = 0;
    while (p1 < word1.size() && p2 < word2.size()) {
      if (word1[p1][i] != word2[p2][j]) {
        return false;
      }
      i++;
      if (i == word1[p1].size()) {
        p1++;
        i = 0;
      }
      j++;
      if (j == word2[p2].size()) {
        p2++;
        j = 0;
      }
    }
    return p1 == word1.size() && p2 == word2.size();
  }
};

int main() {

  Solution test;
  return 0;
}