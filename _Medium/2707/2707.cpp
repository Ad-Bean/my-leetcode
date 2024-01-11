
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个下标从 0 开始的字符串 s 和一个单词字典 dictionary 。
你需要将 s 分割成若干个 互不重叠 的子字符串，每个子字符串都在 dictionary 中出现过。
s 中可能会有一些 额外的字符 不在任何子字符串中。

请你采取最优策略分割 s ，使剩下的字符 最少 。

输入：s = "leetscode", dictionary = ["leet","code","leetcode"]
输出：1
解释：将 s 分成两个子字符串：下标从 0 到 3 的 "leet" 和下标从 5 到 8 的 "code" 。只有 1 个字符没有使用（下标为 4），所以我们返回 1 。
输入：s = "sayhelloworld", dictionary = ["hello","world"]
输出：3
解释：将 s 分成两个子字符串：下标从 3 到 7 的 "hello" 和下标从 8 到 12 的 "world" 。下标为 0 ，1 和 2 的字符没有使用，所以我们返回 3 。
 

题目要求最小化这些额外字符的数量
方法一：动态规划
如果 s[n-1] 是额外字符，子问题是 n-1 长度
对 j 使得 s[j:n-1] 构成的子串在 dictionary，子问题 j-1 

dp[i] 表示 s[:i-1] 的子问题
dp[i] = dp[i-1] + 1, 如果 s[i-1] 是额外字符
dp[i] = min(dp[j]) j \in [0, i-1] 如果 s[j:i-1] 存在于 dictionary 中

方法二：字典树优化
 */
class Solution {
 public:
  int minExtraChar(string s, vector<string>& dictionary) {
    int n = s.size();
    vector<int> d(n + 1, INT_MAX);
    unordered_map<string, int> mp;
    for (auto s : dictionary) {
      mp[s]++;
    }
    d[0] = 0;
    for (int i = 1; i <= n; i++) {
      d[i] = d[i - 1] + 1;
      for (int j = i - 1; j >= 0; j--) {
        if (mp.count(s.substr(j, i - j))) {
          d[i] = min(d[i], d[j]);
        }
      }
    }
    return d[n];
  }
};
int main() {

  Solution test;
  return 0;
}