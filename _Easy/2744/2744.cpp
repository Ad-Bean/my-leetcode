#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个下标从 0 开始的数组 words ，数组中包含 互不相同 的字符串。

如果字符串 words[i] 与字符串 words[j] 满足以下条件，我们称它们可以匹配：

字符串 words[i] 等于 words[j] 的反转字符串。
0 <= i < j < words.length
请你返回数组 words 中的 最大 匹配数目。

注意，每个字符串最多匹配一次。
输入：words = ["cd","ac","dc","ca","zz"]
输出：2
解释：在此示例中，我们可以通过以下方式匹配 2 对字符串：
- 我们将第 0 个字符串与第 2 个字符串匹配，因为 word[0] 的反转字符串是 "dc" 并且等于 words[2]。
- 我们将第 1 个字符串与第 3 个字符串匹配，因为 word[1] 的反转字符串是 "ca" 并且等于 words[3]。
可以证明最多匹配数目是 2 。

方法一：哈希
unordered_map<string,int> mp;
或
unordered_set<string> st;
或自定义哈希 因为题目 words[i].length == 2 且 words[i] 只包含小写英文字母。
unordered_set<int> st;
if (st.count(word[1]))

 */
class Solution {
 public:
  int maximumNumberOfStringPairs(vector<string>& words) {
    unordered_map<string, int> mp;
    int cnt = 0;
    for (string word : words) {
      if (mp[word]) {
        cnt++;
      }
      reverse(word.begin(), word.end());
      mp[word]++;
    }
    return cnt;
  }
};
int main() {

  Solution test;
  return 0;
}
