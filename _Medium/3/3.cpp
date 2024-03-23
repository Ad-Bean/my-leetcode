#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

方法一：滑动窗口
由于是最长子串，考虑滑动窗口 l r
使用哈希表记录当前窗口内字符出现次数
如果出现重复，则 l++ 并 mp[s[l]]-- 直到 mp[s[r]] == 1

0 <= s.length <= 5 * 10^4
注意空字符串
英文字母、数字、符号和空格组成
 */
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int n = s.size();
    if (n == 0) {
      return 0;
    }
    int l = 0, ans = 0;
    unordered_map<char, int> cnt;
    for (int r = 0; r < n; r++) {
      cnt[s[r]]++;
      while (cnt[s[r]] > 1) {
        cnt[s[l]]--;
        l++;
      }
      ans = max(ans, r - l + 1);
    }
    return ans;
  }
};
int main() {

  Solution test;
  cout << test.lengthOfLongestSubstring("abcabcbb") << endl;
  cout << test.lengthOfLongestSubstring("bbbbbbbbbbbbbbbbbbbbbb") << endl;
  cout << test.lengthOfLongestSubstring("abcdefgh") << endl;
  cout << test.lengthOfLongestSubstring(" ") << endl;
  return 0;
}