#include <bits/stdc++.h>

using namespace std;
/*
字母 A-Z 的消息通过以下映射进行了 编码 ：

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
要 解码 已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。例如，"11106" 可以映射为：

"AAJF" ，将消息分组为 (1 1 10 6)
"KJF" ，将消息分组为 (11 10 6)
意，消息不能分组为  (1 11 06) ，因为 "06" 不能映射为 "F" ，这是由于 "6" 和 "06" 在映射中并不等价。

给你一个只含数字的 非空 字符串 s ，请计算并返回 解码 方法的 总数 。

题目数据保证答案肯定是一个 32 位 的整数。

示例 1：

输入：s = "12"
输出：2
解释：它可以解码为 "AB"（1 2）或者 "L"（12）。

方法一：动态规划

dp[i] 表示前 i 个字符的解码方式数
使用一个字符 dp[i] = dp[i-1]
使用两个字符 dp[i] = dp[i-2] 且 s[i-1] 不是 0，10*s[i-1] + s[i] <= 26
dp[0] = 1 空字符串有一个解码方式

*/
typedef long long ll;
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] -'0') <= 26)) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};
int main() {

Solution test;
return 0;
}