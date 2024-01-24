/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 *
 * https://leetcode.cn/problems/course-schedule/description/
 *
 * 你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
 * 
 * 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi]
 * ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。
 * 
 * 
 * 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
 * 
 * 
 * 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 输入：numCourses = 2, prerequisites = [[1,0]]
 * 输出：true
 * 解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
 * 
 * 
 * 输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
 * 输出：false
 * 解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。
 * 
 * 
 * 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= 5000
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * prerequisites[i] 中的所有课程对 互不相同
 * 
 * 方法一：拓扑排序 bfs
 * 
 * 方法二：深搜 dfs
 * 
 * void dfs(int u) {
 *  vis[u] = 1;
 *  for (int nx : g[u]) {
 *      if (vis[nx] == 0) {             // 未搜索
 *          dfs(nx);
 *          if (!valid) return;
 *      } else if (vis[nx] == 1) {      // 搜索中，有环
 *          valid = false;
 *          return;
 *      }
 *  }
 *  vis[u] = 2;
 * }
 * 
 * for (int i = 0; i < numCourses && valid; i++) { if(!vis[i]) dfs(i); }
 * return valid
 * 
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
// @lc code=start
class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> g(numCourses);
    vector<int> ind(numCourses);
    for (const auto& pre : prerequisites) {
      int u = pre[0], v = pre[1];
      // v -> u
      ind[u]++;
      g[v].emplace_back(u);  // DAG
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (ind[i] == 0) {
        q.emplace(i);
      }
    }
    if (q.empty()) {
      return false;
    }
    while (!q.empty()) {
      int sz = q.size();
      for (int i = 0; i < sz; i++) {
        int cur = q.front();
        q.pop();
        for (const auto& nx : g[cur]) {
          ind[nx]--;
          if (ind[nx] == 0) {
            q.emplace(nx);
          }
        }
      }
    }
    for (const auto i : ind) {
      if (i != 0) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end

int main() {
  Solution t;
  vector<vector<int>> pre = {{0, 10}, {3, 18}, {5, 5}, {6, 11}, {11, 14}, {13, 1}, {15, 1}, {17, 4}};
  int n = 20;
  cout << t.canFinish(n, pre) << endl;
}