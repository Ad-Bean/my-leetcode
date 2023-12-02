#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
 public:
  int countCharacters(vector<string>& words, string chars) {
    int mp[26]{};
    for (const char& c : chars) {
      mp[c - 'a']++;
    }
    int sum = 0;
    for (const string& word : words) {
      int temp[26]{};
      copy(mp, mp + 26, temp);
      bool flag = true;
      for (const char& c : word) {
        temp[c - 'a']--;
        if (temp[c - 'a'] < 0) {
          flag = false;
          break;
        }
      }
      if (flag) {
        sum += word.size();
      }
    }
    return sum;
  }
};
int main() {

  Solution test;
  vector<string> words = {"cat", "bt", "hat", "tree"};
  string chars = "atach";
  cout << test.countCharacters(words, chars) << endl;
  return 0;
}
