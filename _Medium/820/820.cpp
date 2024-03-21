#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
单词数组 words 的 有效编码 由任意助记字符串 s 和下标数组 indices 组成，且满足：

words.length == indices.length
助记字符串 s 以 '#' 字符结尾
对于每个下标 indices[i] ，
s 的一个从 indices[i] 开始、到下一个 '#' 字符结束（但不包括 '#'）的 子字符串 恰好与 words[i] 相等
给你一个单词数组 words ，返回成功对 words 进行编码的最小助记字符串 s 的长度 。

输入：words = ["time", "me", "bell"]
输出：10
解释：一组有效编码为 s = "time#bell#" 和 indices = [0, 2, 5] 。
words[0] = "time" ，s 开始于 indices[0] = 0 到下一个 '#' 结束的子字符串，如加粗部分所示 "time#bell#"
words[1] = "me" ，s 开始于 indices[1] = 2 到下一个 '#' 结束的子字符串，如加粗部分所示 "time#bell#"
words[2] = "bell" ，s 开始于 indices[2] = 5 到下一个 '#' 结束的子字符串，如加粗部分所示 "time#bell#"


方法一：
最长的助记字符串一定是 words.join('#) + '#
但是可以发现，如果有共同后缀的单词，则不需要重复存储
所以问题在于如何找到共同后缀，比如 time 和 me，只需要 4 个字符
可以用字典树记录每个单词的逆序


 */
class Solution {
  struct TrieNode {
    TrieNode* child[26];
    int count;
    TrieNode() {
      for (int i = 0; i < 26; i++) {
        child[i] = nullptr;
      }
      count = 0;
    }
  };

 public:
  int minimumLengthEncoding(vector<string>& words) {
    int n = words.size();
    TrieNode* trie = new TrieNode();
    unordered_map<TrieNode*, int> nodes;

    for (int i = 0; i < n; i++) {
      string word = words[i];
      TrieNode* cur = trie;
      for (int j = word.size() - 1; j >= 0; j--) {
        if (cur->child[word[j] - 'a'] == nullptr) {
          cur->child[word[j] - 'a'] = new TrieNode();
          cur->count++;  // 表示当前节点有多少个子节点
        }
        cur = cur->child[word[j] - 'a'];
      }
      nodes[cur] = i;  // 表示当前节点是第 i 个单词的逆序
    }
    int ans = 0;
    for (const auto& [node, idx] : nodes) {
      if (node->count == 0) {  // 如果是叶子节点，表示不是其他单词的后缀
        ans += words[idx].size() + 1;
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  vector<string> words = {"time", "me", "bell"};
  cout << test.minimumLengthEncoding(words) << endl;
  vector<string> words1 = {"t"};
  cout << test.minimumLengthEncoding(words1) << endl;
  vector<string> words2 = {"time", "time", "time", "time"};
  cout << test.minimumLengthEncoding(words2);
  return 0;
}
