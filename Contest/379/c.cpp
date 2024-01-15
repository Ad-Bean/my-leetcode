#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你两个下标从 0 开始的整数数组 nums1 和 nums2 ，它们的长度都是偶数 n 。

你必须从 nums1 中移除 n / 2 个元素，同时从 nums2 中也移除 n / 2 个元素。
移除之后，你将 nums1 和 nums2 中剩下的元素插入到集合 s 中。

返回集合 s可能的 最多 包含多少元素。
输入：nums1 = [1,2,1,2], nums2 = [1,1,1,1]
输出：2
解释：从 nums1 和 nums2 中移除两个 1 。移除后，数组变为 nums1 = [2,2] 和 nums2 = [1,1] 。因此，s = {1,2} 。
可以证明，在移除之后，集合 s 最多可以包含 2 个元素。

输入：nums1 = [1,2,3,4,5,6], nums2 = [2,3,2,3,2,3]
输出：5
解释：从 nums1 中移除 2、3 和 6 ，同时从 nums2 中移除两个 3 和一个 2 。移除后，数组变为 nums1 = [1,4,5] 和 nums2 = [2,3,2] 。因此，s = {1,2,3,4,5} 。
可以证明，在移除之后，集合 s 最多可以包含 5 个元素。 

如果不移除，就是集合的并：容斥原理  |A U B| = |A| + |B| - |A ∩ B|
先移除每个数组中的重复元素，然后再从剩下的数种移除
假设 |A|=n1 |B|=n2 
方法一：贪心   移除
为了让 |A| 尽可能大，所以要移除交集中的元素
为了移除 n/2 个，如果 nums1 和 nums2 没有任何相同元素 则答案就是容斥原理
但一旦有相交，就要考虑是删哪一部分，首先是删交集部分，再删非交集部分

同时由于 nums1 或 nums2 中存在相同元素，首先先剔除这部分，即 n1 和 n2
1. 如果 n1 <= n/2，表示重合的很多，则删掉 n/2 个重合的，尽可能剩下不一样的，n2 <= n/2 同理，用容斥原理得到答案。
2. 如果 n1 > n/2，表示重合的移除之后，还是不够 n/2，则先则尽量移除交集中的以保留不同的数
由于已经移除了 n - n1 个，还需要移除 n1-n/2 个，但假如交集里有共同的，n1 可以少减少 min(n1 - n/2, common) 个

譬如 [1,2,3,4] 和 [4,5,6,7] 此时并集 [1,2,3] [4,5,6,7]
如果交集元素少，则交集全部移除 |A ∩ B| = common，让 nums2 提供这些数

譬如 [1,2,3,4] 和 [1,2,3,4]
如果交集元素多，则移除交集中的 n1 - m 个元素，让 n1 = n/2，所以从交集中移除 min(n1 - n/2, |A ∩ B|) 个元素
 
方法二：贪心  添加

 */
class Solution {
 public:
  int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());
    int common = 0;
    for (const int& num : set1) {
      common += set2.count(num);
    }

    // 首先去掉一些重复元素
    // 去掉重复元素后 nums1 还剩 n1 个
    int n1 = set1.size();
    int n2 = set2.size();
    // 如果去重后，剩余 n1 已经比 n/2 小，则去掉 n/2 后也只能剩这些，用容斥原理得到答案
    int ans = n1 + n2 - common;
    int m = nums1.size() / 2;
    // 如果去重后，剩余 n1 比 n/2 大，
    // 从 交集 中删一些，
    if (n1 > m) {
      int mn = min(n1 - m, common);
      ans -= n1 - mn - m;
      common -= mn;
    }
    if (n2 > m) {
      n2 -= min(n2 - m, common);
      ans -= n2 - m;
    }
    return ans;
  }
};
int main() {
  Solution test;
  vector<int> nums1 = {1, 2, 3, 4};
  vector<int> nums2 = {4, 5, 6, 7};
  cout << test.maximumSetSize(nums1, nums2) << endl;
  return 0;
}