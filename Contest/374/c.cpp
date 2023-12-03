#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
 public:
  int countCompleteSubstrings(string word, int k) {
    int n = word.size();
    unordered_map<char, int> count;
    // 定义一个变量，记录完全子字符串的数目
    int ans = 0;
    // 遍历字符串的所有子串
    for (int i = 0; i < n; i++) {
      count.clear();
      // 遍历子串的每个字符
      for (int j = i; j < n; j++) {
        // 更新字符的出现次数
        count[word[j]]++;
        // 判断是否满足完全子字符串的条件
        if (isComplete(count, k)) {
          // 更新答案
          ans++;
        }
      }
    }
    // 返回答案
    return ans;
  }

  // 定义一个函数，判断一个哈希表是否满足完全子字符串的条件
  bool isComplete(unordered_map<char, int>& count, int k) {
    // 定义一个变量，记录最小的字符
    char minChar = 'z';
    // 定义一个变量，记录最大的字符
    char maxChar = 'a';
    // 遍历哈希表的每个键值对
    for (auto& p : count) {
      // 如果字符出现次数不等于 k，返回 false
      if (p.second != k) {
        return false;
      }
      // 更新最小的字符
      minChar = min(minChar, p.first);
      // 更新最大的字符
      maxChar = max(maxChar, p.first);
    }
    // 如果最大的字符和最小的字符相差至多为 2，返回 true
    if (maxChar - minChar <= 2) {
      return true;
    }
    // 否则，返回 false
    return false;
  }
};

int main() {
  Solution test;
  string word1 = "igigee";
  int k1 = 2;
  cout << test.countCompleteSubstrings(word1, k1) << endl;
  string word2 = "aaabbbccc";
  int k2 = 3;
  cout << test.countCompleteSubstrings(word2, k2);
  return 0;
}