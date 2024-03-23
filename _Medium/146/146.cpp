#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。

方法一：双端队列 + 哈希表
使用一个双端队列存储 key value
队首为最近使用的，每次 get/put 后将其移到队首
但链表无法 O(1) 实现查询，所以使用哈希表存储 key -> 链表节点的指针位置
unordered_map<int, ListNode*> mp
同时使用一个 dummy head 和 dummy tail 连接维护双端链表
 */

struct DListNode {
  int key, value;
  DListNode *prev, *next;
  DListNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
  DListNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
  int size = 0, capacity = 0;
  unordered_map<int, DListNode*> mp;
  DListNode *head, *tail;

  void addToHead(DListNode* node) {
    node->prev = head;        //
    node->next = head->next;  // 顺序很重要，先插入 node
    head->next->prev = node;  // 再更新 head
    head->next = node;        // 否则有可能访问到被释放的内存？
  }

  void removeNode(DListNode* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

 public:
  LRUCache(int capacity) {
    head = new DListNode();
    tail = new DListNode();
    head->next = tail;
    tail->prev = head;
    this->capacity = capacity;
    this->size = 0;
  }

  int get(int key) {
    if (!mp.count(key)) {
      return -1;
    }
    DListNode* node = mp[key];
    removeNode(node);
    addToHead(node);
    return node->value;
  }

  void put(int key, int value) {
    if (!mp.count(key)) {
      DListNode* node = new DListNode(key, value);
      mp[key] = node;
      addToHead(node);
      size++;
      if (size > capacity) {
        DListNode* lfu = tail->prev;
        removeNode(lfu);
        mp.erase(lfu->key);
        delete lfu;
        size--;
      }
    } else {
      DListNode* node = mp[key];
      node->value = value;
      removeNode(node);
      addToHead(node);
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main() {
  LRUCache t = LRUCache(2);
  t.put(1, 1);
  t.put(2, 2);
  cout << t.get(1) << endl;
  return 0;
}
