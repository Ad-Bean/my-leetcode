
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 

给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words， 返回所有二维网格上的单词 。

单词必须按照字母顺序，通过 相邻的单元格 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。

同一个单元格内的字母在一个单词中不允许被重复使用。

方法一：字典树 + DFS

需要遍历每个单元格，从该单元格开始的所有路径
每经过一个单元格就临时修改为 #, 所以是回溯
如果当前路径是 words 中单词，加入到结果，如果是前缀则继续搜索，否则剪枝。

为了快速查找前缀，建立字典树
 */

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
class Solution {
  static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    set<string> res;
    TrieNode* root = new TrieNode();
    for (const auto& word : words) {
      insertTrie(root, word);
    }
    int m = board.size(), n = board[0].size();
    function<bool(int, int, TrieNode*)> dfs = [&](int x, int y, TrieNode* node) {
      char ch = board[x][y];
      if (!node->children.count(ch)) {
        return false;
      }
      node = node->children[ch];
      if (node->word.size() > 0) {
        res.insert(node->word);
      }
      board[x][y] = '#';
      for (int i = 0; i < 4; i++) {
        int nx = x + dirs[i][0], ny = y + dirs[i][1];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
          if (board[nx][ny] != '#') {
            dfs(nx, ny, node);
          }
        }
      }
      board[x][y] = ch;
      return true;
    };
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        dfs(i, j, root);
      }
    }
    vector<string> ans;
    for (const auto& word : res) {
      ans.emplace_back(word);
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}