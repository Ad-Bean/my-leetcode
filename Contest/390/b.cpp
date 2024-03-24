#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

/* 

k
1: 0
2: 1 复制或者加一
3: 2 复制加一或者加一复制加一
4: 2 加一，复制
5: 3 加一复制加一  
6: 3 加一 加一 复制 

如果是偶数，则先加一到一半，然后复制

比如 10 加到 5 复制到 10，一共 5 步
比如 12 加到 4 复制 2 次，一共 5 步

方法一：
枚举 x 个 i 复制，然后加到 k，一共 ceil(k / i) + i - 1 步


*/
class Solution {
 public:
  int minOperations(int k) {
    if (k == 1 || k == 2) {
      return k - 1;
    }
    int ans = INT_MAX;
    for (int i = 2; i < k; i++) {
      ans = min(ans, (int)ceil(1.0 * k / i) - 1 + i - 1);
    }
    return ans;
  }
};
int main() {

  Solution test;
  for (int i = 1; i <= 100; i++) {
    cout << i << " " << test.minOperations(i) << " " << (int)sqrt(i) + 2 << endl;
  }
  return 0;
}