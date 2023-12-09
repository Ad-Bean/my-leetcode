
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
如果整数 x 满足，对于每个数位 d
这个数恰好在 x 中出现过 d 次，则 x 是一个数值平衡数

给整数 n，返回严格，大于 n 的最小数值平衡数

n = 1
输出 22， 2 出现 2次

1 22 122 1333 122333

22 22333

333 3331 33322 


n <= 1e6，如果 n = 1000000 返回为 1224444

方法一：直接枚举
bool isBalance(int x) {
    vector<int> count(10);
    while (x > 0) {
        count[x % 10]++;
        x /= 10;
    }
    for (int d = 0; d < 10; ++d) {
        if (count[d] > 0 && count[d] != d) {
            return false;
        }
    }
    return true;
}
for (int i = n + 1, i <= 1224444; i++) {
    if (isBalance(i)) {
        return i;
    }
}
大于 n 的整数： O(C - n) C=1224444 是可能为答案的最大的数值平衡数

方法二：打表，二分


 */
class Solution {
 public:
  int nextBeautifulNumber(int n) {}
};
int main() {

  Solution test;
  return 0;
}