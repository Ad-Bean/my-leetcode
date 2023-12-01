#include <bits/stdc++.h>
using namespace std;

/* 
字符串 s 和 正整数 k
如果某个字符串满足：
vowels == consonants // 元音数量和辅音数量相等
(v * c) % k == 0
返回字符串 s 中满足条件的子字符串数量

两个约束：假设子字符串长 L
1. sum[i] = sum[j]
i - j = L, (L/2)^2 % k == 0, 有 L^2 == 4mk = (dx)^2 = d^2 * x^2

因子 d， 是 4 的倍数，找到一个最小的 d 满足是 4 的倍数
(i - j) % k' == 0
2. i % k' == j % k'
哈希表统计 pair(i%k, sum[i]) 出现次数
 */
class Solution {
  typedef long long ll;

 public:
  long long beautifulSubstrings(string s, int k) {
    int d = 1;
    while (true) {
      if ((d * d) % (4 * k) == 0) {
        k = d;
        break;
      }
      d++;
    }
    // 对 4k 质因数分解
    unordered_map<char, bool> vowel{
        {'a', true}, {'e', true}, {'i', true}, {'o', true}, {'u', true},
    };
    int n = s.size();
    vector<int> sum(n + 1);
    // 前缀和，元音 +1 辅音 -1
    for (int i = 0; i < n; i++) {
      sum[i + 1] = sum[i] + (vowel[s[i]] ? 1 : -1);
    }

    // 统计 pair (i%k', sum[i]) 出现次数
    ll ans = 0;
    // unordered_map<pair<int, int>, int> cnt; // pii 需要另外的哈希函数
    map<pair<int, int>, int> cnt;
    for (int i = 0; i <= n; i++) {
      pair<int, int> cur = {i % k, sum[i]};
      ans += cnt[cur];
      cnt[cur]++;
    }
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}