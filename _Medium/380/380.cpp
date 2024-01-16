#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
实现RandomizedSet 类：

RandomizedSet() 初始化 RandomizedSet 对象
bool insert(int val) 当元素 val 不存在时，向集合中插入该项，并返回 true ；否则，返回 false 。
bool remove(int val) 当元素 val 存在时，从集合中移除该项，并返回 true ；否则，返回 false 。
int getRandom() 随机返回现有集合中的一项（测试用例保证调用此方法时集合中至少存在一个元素）。每个元素应该有 相同的概率 被返回。
你必须实现类的所有函数，并满足每个函数的 平均 时间复杂度为 O(1) 。

方法一：哈希表

为了使得插入、删除、获取随机的平均时间复杂度是 O(1)
使用哈希表满足插入和删除是 O(1)
此时哈希的值是随机分散的，为了随机获取任意的值，并且每个元素有相同概率返回

需要用另一个数组来存这些数据，而哈希表映射值和下标

插入时，idx[val] = nums.size()  nums.emplace_back(val) 记录下标
删除时，交换 val 和 nums 最后一个，删除下标，将 idx[nums.back()] 的下标更新
随机取，return nums[rand() % nums.size()];
*/
class RandomizedSet {
  vector<int> nums;             // k
  unordered_map<int, int> idx;  // k to index

 public:
  RandomizedSet() { srand((unsigned)time(NULL)); }

  bool insert(int val) {
    if (idx.count(val)) {
      return false;
    }
    nums.emplace_back(val);
    idx[val] = nums.size() - 1;
    return true;
  }

  bool remove(int val) {
    if (!idx.count(val)) {
      return false;
    }
    int val_idx = idx[val];
    idx[nums.back()] = idx[val];
    swap(nums[val_idx], nums[nums.size() - 1]);
    nums.pop_back();
    idx.erase(val);
    return true;
  }

  int getRandom() { return nums[rand() % nums.size()]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
int main() {

  Solution test;
  return 0;
}
