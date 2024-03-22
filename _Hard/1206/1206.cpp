
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

/* 
https://leetcode.cn/problems/design-skiplist/description/
不使用任何库函数，设计一个 跳表 。

跳表 是在 O(log(n)) 时间内完成增加、删除、搜索操作的数据结构。跳表相比于树堆与红黑树，其功能与性能相当，并且跳表的代码长度相较下更短，其设计思想与链表相似。

例如，一个跳表包含 [30, 40, 50, 60, 70, 90] ，然后增加 80、45 到跳表中，以下图的方式操作：
 
跳表中有很多层，每一层是一个短的链表。在第一层的作用下，增加、删除和搜索操作的时间复杂度不超过 O(n)。跳表的每一个操作的平均时间复杂度是 O(log(n))，空间复杂度是 O(n)。

了解更多 : https://oi-wiki.org/ds/skiplist/

在本题中，你的设计应该要包含这些函数：

bool search(int target) : 返回target是否存在于跳表中。
void add(int num): 插入一个元素到跳表。
bool erase(int num): 在跳表中删除一个值，如果 num 不存在，直接返回false. 如果存在多个 num ，删除其中任意一个即可。
注意，跳表中可能存在多个相同的值，你的代码需要处理这种情况。

 
 */
const int MAX_LEVEL = 32;
const double P = 0.25;
struct SkiplistNode {
  int val;
  vector<SkiplistNode*> forward;
  SkiplistNode(int _val, int _maxLevel = MAX_LEVEL) : val(_val), forward(_maxLevel, nullptr) {}
};

class Skiplist {
  SkiplistNode* head;
  int level;
  mt19937 gen{random_device{}()};         //  C++11 伪随机数产生器
  uniform_real_distribution<double> dis;  // 均匀分布随机数

  // 随机生成层数
  int randomLevel() {
    int lv = 1;
    while (dis(gen) < P && lv < MAX_LEVEL) {  // 生成 0 ~ 1 之间的随机数，小于 P 且 小于 MAX_LEVEL 则增加层数
      lv++;
    }
    return lv;
  }

 public:
  Skiplist() : head(new SkiplistNode(-1)), level(0), dis(0, 1) {}

  bool search(int target) {
    SkiplistNode* cur = this->head;
    for (int i = level - 1; i >= 0; i--) {

      while (cur->forward[i] && cur->forward[i]->val < target) {  // 在第 i 层找到最接近 target 的节点
        cur = cur->forward[i];                                    // 大于则不前进
      }                                                           //
    }                                                             //
    cur = cur->forward[0];                                        // 最低层下一个节点
    if (cur && cur->val == target) {                              // 相等则存在
      return true;
    }
    return false;
  }

  void add(int num) {
    vector<SkiplistNode*> update(MAX_LEVEL, head);
    SkiplistNode* cur = this->head;
    for (int i = level - 1; i >= 0; i--) {
      while (cur->forward[i] && cur->forward[i]->val < num) {
        cur = cur->forward[i];
      }
      update[i] = cur;  // 每一层最接近 num 的节点，即 newNode 前一个
    }

    int newLevel = randomLevel();
    this->level = max(this->level, newLevel);  // 更新最大层数
    SkiplistNode* newNode = new SkiplistNode(num, newLevel);

    // 更新新的 Node forward，插入 update[i] 和 update[i]->forward[i] 之间
    for (int i = 0; i < newLevel; i++) {
      newNode->forward[i] = update[i]->forward[i];
      update[i]->forward[i] = newNode;
    }
  }

  bool erase(int num) {
    vector<SkiplistNode*> update(MAX_LEVEL, head);
    SkiplistNode* cur = this->head;
    for (int i = level - 1; i >= 0; i--) {
      while (cur->forward[i] && cur->forward[i]->val < num) {
        cur = cur->forward[i];
      }
      update[i] = cur;      // 每一层最接近 num 的节点，即 num 前一个
    }                       //
    cur = cur->forward[0];  // 最低层是否是 num
    if (!cur || cur->val != num) {
      return false;
    }
    // 每一层都要删除 num
    for (int i = 0; i < level; i++) {
      if (update[i]->forward[i] != cur) {       // 同一层不连续
        break;                                  //
      }                                         //
      update[i]->forward[i] = cur->forward[i];  // 删除 cur
    }
    delete cur;

    while (level > 1 && head->forward[level - 1] == nullptr) {  // 更新层数，维护搜索时间复杂度
      level--;                                                  // 如果则一层为空，则删除
    }                                                           // 注意 level 从 0 开始，和数组下标一样
    return true;
  }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
int main() {

  Solution test;
  return 0;
}