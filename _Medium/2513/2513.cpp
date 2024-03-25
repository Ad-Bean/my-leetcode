#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你两个数组 arr1 和 arr2 ，它们一开始都是空的。你需要往它们中添加正整数，使它们满足以下条件：

arr1 包含 uniqueCnt1 个 互不相同 的正整数，每个整数都 不能 被 divisor1 整除 。
arr2 包含 uniqueCnt2 个 互不相同 的正整数，每个整数都 不能 被 divisor2 整除 。
arr1 和 arr2 中的元素 互不相同 。
给你 divisor1 ，divisor2 ，uniqueCnt1 和 uniqueCnt2 ，请你返回两个数组中 最大元素 的 最小值 。

2 <= divisor1, divisor2 <= 10^5
1 <= uniqueCnt1, uniqueCnt2 < 10^9
2 <= uniqueCnt1 + uniqueCnt2 <= 10^9


输入：divisor1 = 2, divisor2 = 7, uniqueCnt1 = 1, uniqueCnt2 = 3
输出：4
解释：
我们可以把前 4 个自然数划分到 arr1 和 arr2 中。
arr1 = [1] 和 arr2 = [2,3,4] 。
可以看出两个数组都满足条件。
最大值是 4 ，所以返回 4 。
 
方法一：
暴力：对 arr1 和 arr2 分别枚举 
divisor1 * k + i 和 
divisor2 * k + i，k 为整数，i 为 0 到 divisor1 - 1 或 divisor2 - 1
直到找到 uniqueCnt1 和 uniqueCnt2 个数，但是还要额外维护一个哈希表记录已经找到的数
时间复杂度 O(n^2) 

可以发现题目中的关键词 最大元素的最小值 minimum possible maximum integer
同时根据数据范围，也需要考虑 O(nlgn) 的算法

尝试二分：

 */

class Solution {
 public:
  int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {}
};
int main() {

  Solution test;
  return 0;
}