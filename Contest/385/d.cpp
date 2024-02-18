#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
/* 
给你一个下标从 0 开始的字符串数组 words 。

定义一个 布尔 函数 isPrefixAndSuffix ，它接受两个字符串参数 str1 和 str2 ：

当 str1 同时是 str2 的前缀（prefix）和后缀（suffix）时，isPrefixAndSuffix(str1, str2) 返回 true，否则返回 false。
例如，isPrefixAndSuffix("aba", "ababa") 返回 true，因为 "aba" 既是 "ababa" 的前缀，也是 "ababa" 的后缀，但是 isPrefixAndSuffix("abc", "abcd") 返回 false。

以整数形式，返回满足 i < j 且 isPrefixAndSuffix(words[i], words[j]) 为 true 的下标对 (i, j) 的 数量 。

1 <= words.length <= 1e5
1 <= words[i].length <= 1e5
words[i] 仅由小写英文字母组成。
所有 words[i] 的长度之和不超过 5 * 1e5 。

方法一：暴力
枚举所有前缀后缀对，判断是否相等
时间复杂度 O(n^2 * m)
substr 时间复杂度 O(m)

方法二：字典树 + z 函数 / 仅字典树
怎么快速判断 t 的某个长度的前后缀相等？我们可以用 Z 函数解决。

如果只用字典树，对每个字符串 s 看成一个 pair 列表
[(s0,sn-1), (s1,sn-2), ...]

方法三：字符串 双哈希
 */
struct Node {
  unordered_map<int, Node*> son;
  int cnt = 0;
};

typedef long long ll;
class Solution {
 public:
  long long countPrefixSuffixPairs(vector<string>& words) {
    ll ans = 0;
    Node* root = new Node();
    for (string& s : words) {
      int n = s.size();
      auto cur = root;
      for (int i = 0; i < n; i++) {
        int p = (int)(s[i] - 'a') << 5 | (s[n - 1 - i] - 'a');
        if (cur->son[p] == nullptr) {
          cur->son[p] = new Node();
        }
        cur = cur->son[p];
        ans += cur->cnt;
      }
      cur->cnt++;
    }
    return ans;
  }
};

int main() {

  Solution test;
  vector<string> words = {"pa", "papa", "ma", "mama"};
  cout << test.countPrefixSuffixPairs(words) << endl;
  return 0;
}