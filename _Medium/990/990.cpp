#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给定一个由表示变量之间关系的字符串方程组成的数组，
每个字符串方程 equations[i] 的长度为 4，并采用两种不同的形式之一："a==b" 或 "a!=b"。
在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。

只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。 

输入：["a==b","b!=a"]
输出：false
解释：如果我们指定，a = 1 且 b = 1，那么可以满足第一个方程，但无法满足第二个方程。没有办法分配变量同时满足这两个方程。
 
方法一：并查集
如果 a == b 则同属于一个集合，合并
如果 a != b 则不同属于一个集合，如果属于一个集合则返回 false

但是要先合并所有同属一个集合的
再判断 a != b 时，fa[a] 如果等于 fa[b] 则返回 false 表示他们本来在同一个集合 
 */
class Solution {
 public:
  bool equationsPossible(vector<string>& equations) {
    vector<int> fa(26);
    for (int i = 0; i < 26; i++) {
      fa[i] = i;
    }

    function<int(int)> find = [&](int x) {
      if (fa[x] == x) {
        return x;
      }
      return fa[x] = find(fa[x]);
    };

    function<void(int, int)> merge = [&](int x, int y) {
      int fx = find(x), fy = find(y);
      fa[fx] = fy;
    };

    for (const string& s : equations) {
      int x = s[0] - 'a', y = s[3] - 'a';
      if (s[1] == '=') {
        merge(x, y);
      }
    }
    for (const string& s : equations) {
      int x = s[0] - 'a', y = s[3] - 'a';
      if (s[1] == '!') {
        if (find(x) == find(y)) {
          return false;
        }
      }
    }

    return true;
  }
};

int main() {

  Solution test;
  return 0;
}
