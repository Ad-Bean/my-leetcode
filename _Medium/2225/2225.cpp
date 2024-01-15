#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个整数数组 matches 其中 matches[i] = [winneri, loseri] 表示在一场比赛中 winneri 击败了 loseri 。

返回一个长度为 2 的列表 answer ：

answer[0] 是所有 没有 输掉任何比赛的玩家列表。
answer[1] 是所有恰好输掉 一场 比赛的玩家列表。
两个列表中的值都应该按 递增 顺序返回。

注意：

只考虑那些参与 至少一场 比赛的玩家。
生成的测试用例保证 不存在 两场比赛结果 相同 。
输入：matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
输出：[[1,2,10],[4,5,7,8]]
解释：
玩家 1、2 和 10 都没有输掉任何比赛。
玩家 4、5、7 和 8 每个都输掉一场比赛。
玩家 3、6 和 9 每个都输掉两场比赛。
因此，answer[0] = [1,2,10] 和 answer[1] = [4,5,7,8] 。

方法一：哈希
记录所有每个人的输的次数

 */
class Solution {
 public:
  vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    unordered_map<int, int> loses;
    for (const auto& match : matches) {
      int w = match[0], l = match[1];
      if (loses.find(w) == loses.end()) {
        loses[w] = 0;
      }
      loses[l]++;
    }
    vector<vector<int>> ans(2);
    for (const auto& [k, v] : loses) {
      if (v == 0) {
        ans[0].emplace_back(k);
      } else if (v == 1) {
        ans[1].emplace_back(k);
      }
    }
    sort(ans[0].begin(), ans[0].end());
    sort(ans[1].begin(), ans[1].end());
    return ans;
  }
};
int main() {

  Solution test;
  return 0;
}
