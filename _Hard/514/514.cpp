/*
 * @lc app=leetcode.cn id=514 lang=cpp
 *
 * [514] 自由之路
 *
 * https://leetcode.cn/problems/freedom-trail/description/
 *
 *
 * 电子游戏“辐射4”中，任务 “通向自由” 要求玩家到达名为 “Freedom Trail Ring” 的金属表盘，并使用表盘拼写特定关键词才能开门。
 * 
 * 给定一个字符串 ring ，表示刻在外环上的编码；给定另一个字符串 key ，表示需要拼写的关键词。您需要算出能够拼写关键词中所有字符的最少步数。
 * 
 * 最初，ring 的第一个字符与 12:00 方向对齐。您需要顺时针或逆时针旋转 ring 以使 key 的一个字符在 12:00
 * 方向对齐，然后按下中心按钮，以此逐个拼写完 key 中的所有字符。
 * 
 * 旋转 ring 拼出 key 字符 key[i] 的阶段中：
 * 
 * 
 * 您可以将 ring 顺时针或逆时针旋转 一个位置 ，计为1步。旋转的最终目的是将字符串 ring 的一个字符与 12:00
 * 方向对齐，并且这个字符必须等于字符 key[i] 。
 * 如果字符 key[i] 已经对齐到12:00方向，您需要按下中心按钮进行拼写，这也将算作 1 步。按完之后，您可以开始拼写 key
 * 的下一个字符（下一阶段）, 直至完成所有拼写。
 * 
 * 
 * 输入: ring = "godding", key = "gd"
 * 输出: 4
 * 解释:
 * ⁠对于 key 的第一个字符 'g'，已经在正确的位置, 我们只需要1步来拼写这个字符。 
 * ⁠对于 key 的第二个字符 'd'，我们需要逆时针旋转 ring "godding" 2步使它变成 "ddinggo"。
 * ⁠当然, 我们还需要1步进行拼写。
 * ⁠因此最终的输出是 4。
 * 
 * 
 * 示例 2:
 * 
 * 输入: ring = "godding", key = "godding"
 * 输出: 13
 * 解释
 * 1 + 2 * 6 = 13
 * 
 * 1 <= ring.length, key.length <= 100
 * ring 和 key 只包含小写英文字母
 * 保证 字符串 key 一定可以由字符串  ring 旋转拼出
 * 
 * 
 * 方法一：记忆化搜索 O(n(26+m))
 * 假设 s = goddid, t = gdi 初始状态为 g
 * 第一次按下后题目变成了 s = goddid, t = di 且初始状态为 s[0] 下的最小旋转次数
 * 如果要旋转得到 s[i] = d
 * - 旋转到 s[0]=g 右边最近的 s[2]=d，旋转两次，问题变成 s=goddid, t=i，初始状态为 s[2] 状态
 * - 旋转到 s[0]=g 左边最近的 s[5]=d，旋转一次，问题变成 s=goddid, t=i，初始状态为 s[5] 状态
 * 
 * 于是可以递归解决子问题，给定 s 和 t'，初始状态为 s[i] 计算 t' 的最小宣传次数
 * t' 是 t 的后缀，于是 dfs(j, i) 有后缀 t[j] 到 t[len(t)-1]
 * 
 * 如果 s[i] == t[j] 无需旋转，dfs(j, i) = dfs(j + 1, i)
 * 如果 s[i] != t[j] 分类讨论
 * -  s[i] 左边最近，旋转 i - l 或是 n - (i - l)
 * -  s[i] 右边最近，旋转 r - i 或是 n - (r - i) 
 * 
 * 取最小值 dfs(j, i) = min(dfs(j + 1, l) + kl, dfs(j + 1, r) + kr)
 * 
 * 使用记忆化搜索 记录 memo[j][i] 的值
 * 
 * 官方题解：动态规划 Omn^2 / 零茶山 DP
 * https://leetcode.cn/problems/freedom-trail/solutions/2623534/onm-zuo-fa-cong-ji-yi-hua-sou-suo-dao-di-dnec
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

// @lc code=start
class Solution {
 public:
  int findRotateSteps(string s, string t) {
    int n = s.size(), m = t.size();

    // 记录每个字母 最后 出现的下标
    vector<int> pos(26);
    for (int i = 0; i < n; i++) {
      pos[s[i] - 'a'] = i;
    }
    // 记录每个 s[i] 左边 a-z 的最近下标
    vector<vector<int>> left(n, vector<int>(26));
    for (int i = 0; i < n; i++) {
      left[i] = pos;        // 对 0 来说就是左边最后出现的一次
      pos[s[i] - 'a'] = i;  // 边走边更新，更新最后出现的一次
    }

    // 记录每个字母 首次 出现的下标
    for (int i = n - 1; i >= 0; i--) {
      pos[s[i] - 'a'] = i;
    }
    // 记录每个 s[i] 右边 a-z 的最近下标
    vector<vector<int>> right(n, vector<int>(26));
    for (int i = n - 1; i >= 0; i--) {
      right[i] = pos;       // 对 n-1 来说就是右边首次出现的一次
      pos[s[i] - 'a'] = i;  //
    }

    vector<vector<int>> memo(m, vector<int>(n, -1));
    function<int(int, int)> dfs = [&](int j, int i) -> int {
      if (j == m) {
        return 0;              // 完成
      }                        //
      if (memo[j][i] != -1) {  // 已搜索
        return memo[j][i];
      }

      if (s[i] == t[j]) {
        memo[j][i] = dfs(j + 1, i);  // 不用旋转
        return memo[j][i];
      }
      // 找到右边或者左边最近的
      int l = left[i][t[j] - 'a'], r = right[i][t[j] - 'a'];
      // l > i ? n - (l - i) : i - l 表示向左旋转几次
      memo[j][i] = min(dfs(j + 1, l) + (l > i ? n - l + i : i - l), dfs(j + 1, r) + (r < i ? n - i + r : r - i));
      return memo[j][i];
    };
    return dfs(0, 0) + m;  // 加 m 是按下的次数
  }
};
// @lc code=end
