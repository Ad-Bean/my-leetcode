#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

/* 
给定两个字符串 order 和 s 。order 的所有字母都是 唯一 的，并且以前按照一些自定义的顺序排序。

对 s 的字符进行置换，使其与排序的 order 相匹配。
更具体地说，如果在 order 中的字符 x 出现字符 y 之前，那么在排列后的字符串中， x 也应该出现在 y 之前。

返回 满足这个性质的 s 的任意一种排列 。

方法一：自定义排序
对 order 中每个字符，给一个权值，如果必须在前面，则权值更大。
未出现的就给 0

时间复杂度：O(nlogn)

方法二：计数排序
由于字符集大小 26，使用计数排序
先用哈希/数组 统计每个字符在 s 出现的次数

然后遍历 order，如果当前 cnt[ch] 大于 0，则将 ch 重复 cnt[ch] 次加入答案 ans 中 
ans += string(cnt[ch], ch) 并且 cnt[ch] = 0

最后遍历 cnt，将剩余的字符加入答案

 */
class Solution {
 public:
  string customSortString(string order, string s) {
    int cnt[26] = {0};
    int n = order.size();
    for (int i = 0; i < n; i++) {
      cnt[order[i] - 'a'] = n - i;
    }
    sort(s.begin(), s.end(), [&](char& a, char& b) { return cnt[a - 'a'] > cnt[b - 'a']; });
    return s;
  }
};
int main() {

  Solution test;
  return 0;
}