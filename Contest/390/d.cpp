#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct TrieNode {
  unordered_map<char, TrieNode*> child;
  int idx;
  int length;
  TrieNode() : idx(INT_MAX), length(INT_MAX) {}
};

void addWord(TrieNode* root, string& word, int idx) {
  TrieNode* node = root;
  int n = word.size();
  for (int i = n - 1; i >= 0; i--) {
    char ch = word[i];
    if (!node->child.count(ch)) {
      node->child[ch] = new TrieNode();
    }
    if (node->length > n) {
      node->length = n;
      node->idx = idx;
    }
    node = node->child[ch];
  }
  if (node->length > n) {
    node->length = n;
    node->idx = idx;
  }
}

TrieNode* queryWord(TrieNode* root, string& word) {
  TrieNode* node = root;
  int n = word.size();
  for (int i = n - 1; i >= 0; i--) {
    char ch = word[i];
    if (node->child[ch] == nullptr) {
      return node;
    }
    node = node->child[ch];
  }
  return node;
}

class Solution {
 public:
  vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
    TrieNode* root = new TrieNode();
    for (int i = 0; i < wordsContainer.size(); i++) {
      addWord(root, wordsContainer[i], i);
    }

    vector<int> ans;
    for (int i = 0; i < wordsQuery.size(); i++) {
      TrieNode* node = queryWord(root, wordsQuery[i]);
      ans.emplace_back(node->idx);
    }
    return ans;
  }
};

int main() {

  Solution test;
  vector<string> wordsContainer = {"abcd", "bcd", "xbcd"};
  vector<string> wordsQuery = {"cd", "bcd", "xyz"};
  vector<int> ans = test.stringIndices(wordsContainer, wordsQuery);
  for (auto x : ans) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}