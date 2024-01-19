
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给你一个整数，将其转为罗马数字。

罗马转整数，是唯一的，每次选择尽可能大的
比如 140 先拿出 100 
40 则用 LX，
所以记录所有能够表示的数字的罗马数字， 1000, 900, 500, 400
从大到小表示每次分解 num 即可


方法一：从大到小分解
贪心


 */
// 类外的数组不需要明确大小 速度快
/* 
const pair<int, string> roman[] = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
                                       {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
                                       {5, "V"},    {4, "IV"},   {1, "I"}};
 */
class Solution {
  // 在类里的数组需要明确大小

 public:
  string intToRoman(int num) {
    pair<int, string> roman[] = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"},
                                 {40, "XL"},  {10, "X"},   {9, "IX"},  {5, "V"},    {4, "IV"},  {1, "I"}};
    string ans;
    for (const auto& [k, v] : roman) {
      while (num >= k) {
        num -= k;
        ans += v;
      }
      if (num == 0) {
        break;
      }
    }
    return ans;
  }
};
int main() {

  Solution test;
  cout << test.intToRoman(140) << endl;
  return 0;
}