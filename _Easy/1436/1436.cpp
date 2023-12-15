
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一份旅游线路图，该线路图中的旅行线路用数组 paths 表示，其中 paths[i] = [cityAi, cityBi] 表示该线路将会从 cityAi 直接前往 cityBi 。请你找出这次旅行的终点站，即没有任何可以通往其他城市的线路的城市。

题目数据保证线路图会形成一条不存在循环的线路，因此恰有一个旅行终点站。

方法一：
保证了无环
建图后拓扑 -> 哈希表建图（实际上都是一对一）
不需要 vis，有向无环

方法二：
由于保证只有 A->B，则终点一定在 Bi 中
所有 Bi 中，没出现过在 Ai 中的就是终点

 */
class Solution {
 public:
  string destCity(vector<vector<string>>& paths) {
    unordered_map<string, bool> vis;
    for (const auto& path : paths) {
      vis[path[0]] = true;
    }
    for (const auto& path : paths) {
      if (!vis[path[1]]) {
        return path[1];
      }
    }
    return "";
  }
};
int main() {
  vector<vector<string>> paths = {{"London", "New York"}, {"New York", "Lima"}, {"Lima", "Sao Paulo"}};
  Solution test;
  cout << test.destCity(paths) << endl;
  return 0;
}