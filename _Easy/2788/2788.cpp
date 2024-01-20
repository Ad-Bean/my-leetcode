#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个字符串数组 words 和一个字符 separator ，请你按 separator 拆分 words 中的每个字符串。

返回一个由拆分后的新字符串组成的字符串数组，不包括空字符串 。

注意

separator 用于决定拆分发生的位置，但它不包含在结果字符串中。
拆分可能形成两个以上的字符串。
结果字符串必须保持初始相同的先后顺序。

方法一：模拟
Go, javascript, python 都有 split
cpp 用 stringstream ss + getline
或者直接双指针
for (int i = 0; i < n; i++) {
    int j = i;
    while (j < n && w[j] != separator) j++;
    if (i == j) continue;
    res.push_back(w.substr(i, j - i));
    i = j;
}
 */
class Solution {
 public:
  vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
    vector<string> ans;
    for (const string& word : words) {
      stringstream ss(word);
      string sub;
      while (getline(ss, sub, separator)) {
        if (!sub.empty()) {
          ans.emplace_back(sub);
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
