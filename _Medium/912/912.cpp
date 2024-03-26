#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个整数数组 nums，请你将该数组升序排列。

 
方法一：快速排序
由于快速排序对于有序/重复元素较多的数组性能较差，因此需要随机选择 pivot
并且需要用三指针来处理相等元素，从而减少递归深度

随机选择 pivot = rand() % (r - l + 1) + l
三指针  i = l - 1, j = r + 1
将数组分为 [l:i] [i:j] [j:r] 三部分
while (i < j) {
    while (nums[++i] < pivot) {}   // 会跳过相等元素
    while (nums[--j] > pivot) {}   // 会跳过相等元素
    if (i < j) {                   // 
        swap(nums[i], nums[j]);    //
    }
}
[l:i] 全部小于等于 pivot 
[i:j]
[j:r] 全部大于等于 pivot
递归处理 [l:i] [j:r]


方法二：归并排序
方法三：堆排序

 */
class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    function<void(int, int)> quick_sort = [&](int l, int r) {
      if (l >= r) {
        return;
      }
      //   mt19937 gen{random_device{}()};         // mt19937, random_device 是一个 class
      //   uniform_int_distribution<> dist(l, r);  //
      int pivot = rand() % (r - l + 1) + l;  // 生成 [l, r] 之间的随机数
      int pivot_val = nums[pivot];           //
      int i = l - 1, j = r + 1;              // 三指针
      while (i < j) {                        //
        while (nums[++i] < pivot_val) {}     // 会跳过相等元素
        while (nums[--j] > pivot_val) {}     //
        if (i < j) {
          swap(nums[i], nums[j]);
        }
      }
      // cout << l << " " << i << " " << j << " " << r << endl;
      quick_sort(l, i - 1);
      quick_sort(j + 1, r);
    };

    int n = nums.size();
    quick_sort(0, n - 1);
    return nums;
  }
};
int main() {

  Solution test;
  // vector<int> nums = {5, 1, 1, 2, 0, 0};
  // vector<int> res = test.sortArray(nums);
  // for (int i = 0; i < res.size(); i++) {
  //   cout << res[i] << " ";
  // }
  // cout << endl;
  vector<int> nums2 = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
  vector<int> res2 = test.sortArray(nums2);
  for (int i = 0; i < res2.size(); i++) {
    cout << res2[i] << " ";
  }
  cout << endl;
  return 0;
}
