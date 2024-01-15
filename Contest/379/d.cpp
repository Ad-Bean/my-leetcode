#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

/* 
3003. 执行操作后的最大分割数量
给你一个下标从 0 开始的字符串 s 和一个整数 k。

你需要执行以下分割操作，直到字符串 s 变为 空：

选择 s 的最长前缀，该前缀最多包含 k 个 不同 字符。
删除 这个前缀，并将分割数量加一。如果有剩余字符，它们在 s 中保持原来的顺序。
执行操作之 前 ，你可以将 s 中 至多一处 下标的对应字符更改为另一个小写英文字母。

在最优选择情形下改变至多一处下标对应字符后，用整数表示并返回操作结束时得到的最大分割数量。

输入：s = "accca", k = 2
输出：3
解释：在此示例中，为了最大化得到的分割数量，可以将 s[2] 改为 'b'。
s 变为 "acbca"。
按照以下方式执行操作，直到 s 变为空：
- 选择最长且至多包含 2 个不同字符的前缀，"acbca"。
- 删除该前缀，s 变为 "bca"。现在分割数量为 1。
- 选择最长且至多包含 2 个不同字符的前缀，"bca"。
- 删除该前缀，s 变为 "a"。现在分割数量为 2。
- 选择最长且至多包含 2 个不同字符的前缀，"a"。
- 删除该前缀，s 变为空。现在分割数量为 3。
因此，答案是 3。
可以证明，分割数量不可能超过 3。

方法一：记忆化搜索  记录字符集合
dfs(i, mask, changed) 表示遍历到 s[i] 的最大分割数
前 i 个的字符集合是 mask
是否修改状态 changed

- 如果不改 s[i]:
  - 如果 s[i] 加入 mask 后集合大小 > k，则 s[i] 分入下一段，答案 dfs(i+1, {s[i]}, changed) + 1
  - 如果 s[i] 加入 mask 后集合大小 <= k，答案 dfs(i+1, mask insert s[i], changed)
- 如果 changed = false 可以修改 s[i] 枚举改成第 j 个字母
  - 如果 j 加入 mask 集合大小 > k，则 j 分到下一子串，答案 dfs(i+1, {j}, true) + 1
  - 如果 j 加入 mask 集合大小 <= k，答案 dfs(i+1, mask insert j, true)
取所有情况的最大值，递归边界 dfs(n, *, *) 

方法二：前后缀分解
https://leetcode.cn/problems/maximize-the-number-of-partitions-after-operations/solutions/2595072/ji-yi-hua-sou-suo-jian-ji-xie-fa-pythonj-6g5z/
 */

class Solution {
  typedef long long ll;

 public:
  int maxPartitionsAfterOperations(string s, int k) {
    unordered_map<ll, int> memo;
    int n = s.size();
    function<int(int, int, bool)> dfs = [&](int i, int mask, bool changed) -> int {
      if (i == n) {
        return 1;  //
      }
      // 记忆化
      ll arg_mask = (ll)i << 32 | mask << 1 | changed;
      if (memo.find(arg_mask) != memo.end()) {
        return memo[arg_mask];
      }

      int res = 0;
      int bit = 1 << (s[i] - 'a');                         // 掩码
      int new_mask = mask | bit;                           // 1. 如果不改
      if (__builtin_popcount(new_mask) > k) {              // 分割到下一段
        res = dfs(i + 1, bit, changed) + 1;                //
      } else {                                             // 继续这一段
        res = dfs(i + 1, new_mask, changed);               //
      }                                                    //
      if (!changed) {                                      // 2. 如果改
        for (int j = 0; j < 26; j++) {                     //
          new_mask = mask | (1 << j);                      // 改成 j
          if (__builtin_popcount(new_mask) > k) {          //
            res = max(res, dfs(i + 1, 1 << j, true) + 1);  // 下一段分割
          } else {                                         //
            res = max(res, dfs(i + 1, new_mask, true));    // 下一段不分割
          }
        }
      }
      return memo[arg_mask] = res;
    };
    return dfs(0, 0, false);
  }
};
int main() {

  Solution test;
  return 0;
}