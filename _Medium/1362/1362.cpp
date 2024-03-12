#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
/* 
给你一个整数 num，请你找出同时满足下面全部要求的两个整数：

两数乘积等于  num + 1 或 num + 2
以绝对差进行度量，两数大小最接近
你可以按任意顺序返回这两个整数。

输入：num = 8
输出：[3,3]
解释：对于 num + 1 = 9，最接近的两个因数是 3 & 3；对于 num + 2 = 10, 最接近的两个因数是 2 & 5，因此返回 3 & 3 。

输入：num = 123
输出：[5,25]

输入：num = 999
输出：[40,25]

方法一：
首先为了使得 x * y = num + 1 或 num + 2，并且两数接近
sqrt(num + 1) 然后对两个数进行枚举
比如 num = 999，i = sqrt(num + 1) = 31，如果 num+1 % i == 0 并且 abs(i - n/i) 小于当前答案则更新
同样对于 sqrt(num + 2) 进行枚举
 */

class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> ans {0, INT_MAX};
        for (int i = sqrt(num + 1); i > 0; i--) {
            if ((num + 1) % i == 0) {
                if (abs((num + 1) / i - i) < abs(ans[1] - ans[0])) {
                    ans[0] = i;
                    ans[1] = (num + 1) / i;
                }
            }
        }
        for (int i = sqrt(num + 2); i > 0; i--) {
            if ((num + 2) % i == 0) {
                if (abs((num + 2) / i - i) < abs(ans[1] - ans[0])) {
                    ans[0] = i;
                    ans[1] = (num + 2) / i;
                }
            }
        }
        return ans;
     }
};
int main() {
    
    Solution test;
    return 0;
} 
