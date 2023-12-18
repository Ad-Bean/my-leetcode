
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
两个数对 (a, b) 和 (c, d) 之间的 乘积差 定义为 (a * b) - (c * d) 。

例如，(5, 6) 和 (2, 7) 之间的乘积差是 (5 * 6) - (2 * 7) = 16 。

给你一个整数数组 nums ，选出四个 不同的 下标 w、x、y 和 z ，
使数对 (nums[w], nums[x]) 和 (nums[y], nums[z]) 之间的 乘积差 取到 最大值 。

返回以这种方式取得的乘积差中的 最大值 。


4 <= nums.length <= 1e4

方法一：排序
本质是找最大的两个 和最小的两个
sort(nums.begin(), nums.end());
int n = nums.size();
return nums[n - 1] * nums[n - 2] - nums[0] * nums[1];

方法二：遍历
维护最大和次大
维护最小和次小
 */
class Solution {
 public:
  int maxProductDifference(vector<int>& nums) {
    int n = nums.size();
    int maxx = max(nums[0], nums[1]), maxxx = min(nums[0], nums[1]);
    int minn = min(nums[0], nums[1]), minnn = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
      if (nums[i] > maxx) {
        maxxx = maxx;
        maxx = nums[i];
      } else if (nums[i] > maxxx) {
        maxxx = nums[i];
      }
      if (nums[i] < minn) {
        minnn = minn;
        minn = nums[i];
      } else if (nums[i] < minnn) {
        minnn = nums[i];
      }
    }
    return maxx * maxxx - minn * minnn;
  }
};
int main() {

  Solution test;
  return 0;
}