#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
You are given an array of strings words (0-indexed).

In one operation, pick two distinct indices i and j,
 where words[i] is a non-empty string, and move **any** character from words[i] to any position in words[j].

Return true if you can make **every string** in words equal using any number of operations, and false otherwise.


Input: words = ["abc","aabc","bc"]
Output: true
Explanation: Move the first 'a' in words[1] to the front of words[2],
to make words[1] = "abc" and words[2] = "abc".
All the strings are now equal to "abc", so return true.


注释：any 是任意一个，最终使得所有字符串相等

方法一：哈希
所有字符必须出现 n * k 次

c++ 11 std::all_of https://en.cppreference.com/w/cpp/algorithm/all_any_none_of
        all true,
        none false

*/
class Solution {
 public:
  bool makeEqual(vector<string>& words) {
    int n = words.size();
    int mp[26] = {};
    for (const string& word : words) {
      for (const char& c : word) {
        mp[c - 'a']++;
      }
    }

    return all_of(mp, mp + 26, [&](int x) { return x % n == 0; });
  }
};
int main() {

  Solution test;
  return 0;
}
