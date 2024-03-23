#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 

给定一个单链表 L 的头节点 head ，单链表 L 表示为：
L0 → L1 → … → Ln - 1 → Ln
请将其重新排列后变为：

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

方法一：空间复杂度 O(n)
用数组表示，然后修改

方法二：空间复杂度 O(1)
中点 分割链表 l1 l2 l3 l4 -> l1 l2 | l3 l4
反转 链表后半部分 L2 L3 -> L3 L2
合并 两个链表 L0 -> L3 -> L1 -> L2
*/

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
  ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr, *curr = head;
    while (curr) {
      ListNode* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }

 public:
  void reorderList(ListNode* head) {
    ListNode *l = head, *r = head;
    while (r->next && r->next->next) {
      l = l->next;
      r = r->next->next;
    }
    ListNode* ll = head;                  //
    ListNode* rr = reverseList(l->next);  // 保证前半部分比后半部分相等或多一个节点
    l->next = nullptr;                    // 此时断开 [1,2,3] [5,4]

    while (ll && rr) {
      ListNode* t1 = ll->next;
      ListNode* t2 = rr->next;
      ll->next = rr;
      rr->next = t1;
      ll = t1;
      rr = t2;
    }
  }
};
int main() {

  Solution test;
  ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  test.reorderList(head);
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
  return 0;
}
