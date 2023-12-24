#include <bits/stdc++.h>

using namespace std;
/*
给你一个用无限二维网格表示的花园，每一个 整数坐标处都有一棵苹果树。
整数坐标 (i, j) 处的苹果树有 |i| + |j| 个苹果。

你将会买下正中心坐标是 (0, 0) 的一块 正方形土地 ，且每条边都与两条坐标轴之一平行。

给你一个整数 neededApples ，请你返回土地的 最小周长 ，
使得 至少 有 neededApples 个苹果在土地 里面或者边缘上。

|x| 的值定义为：

如果 x >= 0 ，那么值为 x
如果 x < 0 ，那么值为 -x

need = 1
ans  = 2
边长为 1 没有以 0 0 为中心的正方形
边长 2， 1*4 + 2*4 = 12
边长 3 ?
边长 4, 2*4+3*8+4*4 +S1 = 8+24+16 + 12=60     n(n/2+1)(n+1) = 4*3*5 = 60

方法一：枚举
枚举直到边长 Sn >= neededApples

方法二：二分
l= 1, r=floor(neededapple^(1/3))
while(l<=r) {
    ll m = (l+r) / 2;
    if(2*m*(m+1)*(m*2+1) >= need) {
        ans = m;
        r = m -1;
    } else {
        l = m+1;
    }
}
return ans * 8;

方法三：数学
cbrt(needed / 4.0)
if (2*n*(n+1)*(2*n+1) < need) {
    n++;
}
return 8*n;
*/
typedef long long ll;
class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        ll n = 2;
        while(n*(n/2 + 1)*(n+1) < neededApples) {
            n+=2;
        }
        return n;
    }
};



int main() {

Solution test;
return 0;
}