#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
小镇里有 n 个人，按从 1 到 n 的顺序编号。传言称，这些人中有一个暗地里是小镇法官。

如果小镇法官真的存在，那么：

小镇法官不会信任任何人。
每个人（除了小镇法官）都信任这位小镇法官。
只有一个人同时满足属性 1 和属性 2 。
给你一个数组 trust ，其中 trust[i] = [ai, bi] 表示编号为 ai 的人信任编号为 bi 的人。

如果小镇法官存在并且可以确定他的身份，请返回该法官的编号；否则，返回 -1 。

方法一：入度出度
法官的入度为 n - 1，出度为 0

 */
class Solution {
 public:
  int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> in(n + 1), out(n + 1);
    for (const auto& t : trust) {
      out[t[0]]++;
      in[t[1]]++;
    }
    for (int i = 1; i <= n; i++) {
      if (in[i] == n - 1 && out[i] == 0) {
        return i;
      }
    }
    return -1;
  }
};
int main() {

  Solution test;
  return 0;
}
