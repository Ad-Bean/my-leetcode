#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个用字符数组 tasks 表示的 CPU 需要执行的任务列表，用字母 A 到 Z 表示，以及一个冷却时间 n。
每个周期或时间间隔允许完成一项任务。
任务可以按任何顺序完成，但有一个限制：两个 相同种类 的任务之间必须有长度为 n 的冷却时间。

返回完成所有任务所需要的 最短时间间隔 。


输入：tasks = ["A","A","A","B","B","B"], n = 2
输出：8
解释：A -> B -> (待命) -> A -> B -> (待命) -> A -> B
     在本示例中，两个相同类型任务之间必须间隔长度为 n = 2 的冷却时间，而执行一个任务只需要一个单位时间，所以中间出现了（待命）状态。

方法一：贪心
首先对于同一类的任务，每个任务执行时间 i, i+n+1, i+2n+2, ..., 
假设任务数量 m，则总耗时 (n+1) * (m-1) + 1 
因为最后一个任务只需要 1 的时间

假设任务数最多的任务有 maxx 个，共有 tott 种任务数最多的任务 (tott 必然 >= 1)
穿插之后总耗时 (n + 1) * (maxx - 1) + 1
但是如果有多种任务数量都是 maxx，那么可以多穿插一次，而不需要冻结即 (n + 1) * (maxx - 1) + tott
 */
class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    int types[26] = {0};
    int maxx = 0, tott = 0;
    for (const char& task : tasks) {
      types[task - 'A']++;
      maxx = max(maxx, types[task - 'A']);
    }
    for (int i = 0; i < 26; i++) {
      if (types[i] == maxx) {
        tott++;  // 共有几种任务数量最多
      }
    }
    int m = tasks.size();
    return max(m, (n + 1) * (maxx - 1) + tott);
  }
};
int main() {

  Solution test;
  return 0;
}
