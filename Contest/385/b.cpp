#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct TrieNode {
  string word;
  unordered_map<char, TrieNode*> children;
  TrieNode() { this->word = ""; }
};

void insertTrie(TrieNode* root, const string& word) {
  TrieNode* node = root;
  for (const auto& ch : word) {
    if (!node->children.count(ch)) {
      node->children[ch] = new TrieNode();
    }
    node = node->children[ch];
  }
  node->word = word;
}

int findWord(TrieNode* root, const string& word) {
  TrieNode* node = root;
  int n = word.size();
  for (int i = 0; i < n; i++) {
    if (!node->children.count(word[i])) {
      return i;
    }
    node = node->children[word[i]];
  }
  return n;
}

class Solution {
 public:
  int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    TrieNode* root = new TrieNode();
    for (const auto& a : arr1) {
      insertTrie(root, to_string(a));
    }
    int maxlen = 0;
    for (const auto& a : arr2) {
      int len = findWord(root, to_string(a));
      maxlen = max(maxlen, len);
    }
    return maxlen;
  }
};

int main() {

  Solution test;
  vector<int> arr1 = {1, 10, 100};
  vector<int> arr2 = {1000};
  cout << test.longestCommonPrefix(arr1, arr2) << endl;
  return 0;
}