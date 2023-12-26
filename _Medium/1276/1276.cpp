#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
给你两个整数 tomatoSlices 和 cheeseSlices，分别表示番茄片和奶酪片的数目。不同汉堡的原料搭配如下：

巨无霸汉堡：4 片番茄和 1 片奶酪
小皇堡：2 片番茄和 1 片奶酪
请你以 [total_jumbo, total_small]（[巨无霸汉堡总数，小皇堡总数]）的格式返回恰当的制作方案，使得剩下的番茄片 tomatoSlices 和奶酪片 cheeseSlices 的数量都是 0。

如果无法使剩下的番茄片 tomatoSlices 和奶酪片 cheeseSlices 的数量为 0，就请返回 []。


输入：tomatoSlices = 16, cheeseSlices = 7
输出：[1,6]
解释：制作 1 个巨无霸汉堡和 6 个小皇堡需要 4*1 + 2*6 = 16 片番茄和 1 + 6 = 7 片奶酪。不会剩下原料。
示例 2：

输入：tomatoSlices = 17, cheeseSlices = 4
输出：[]
解释：只制作小皇堡和巨无霸汉堡无法用光全部原料。


方法一：
设 x 和 y
4x+2y = a
x+y = b
求解 x 和 y
2x + 2y = 2b
x = (a - 2b) / 2
y = (4b - a) / 2
*/
class Solution {
public:
    vector<int> numOfBurgers(int a, int b) {
        if ((a - 2 * b) >= 0 && (4 * b - a ) >= 0 && (a - 2 * b) % 2 == 0 && (4 * b - a) % 2 == 0) {
            return vector<int> {(a-2*b) / 2, (4*b - a) / 2};
        }
        return vector<int>{};
    }
};
int main() {

Solution test;
return 0;
}