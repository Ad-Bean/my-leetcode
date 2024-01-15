#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
/* 
给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。

方法一：有序去重
重复的元素在链表中出现的位置是连续的，

由于链表的头节点可能会被删除，因此我们需要额外使用一个哑节点（dummy node）指向链表的头节点。

指针 cur 指向链表的哑节点，随后开始对链表进行遍历
如果当前结点的下两个 cur.next 与 cur.next.next 对应的元素相同
就需要将下一个结点 cur.next 以及所有后面拥有相同元素值的链表节点全部删除

记下这个元素值 v，随后不断将下一个结点 cur.next 从链表中移除: cur->next = cur->next->next
 */
class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head) {
      return head;
    }
    ListNode* dummy = new ListNode(-999, head);
    ListNode* curr = dummy;
    while (curr->next && curr->next->next) {
      if (curr->next->val == curr->next->next->val) {
        int v = curr->next->val;
        while (curr->next && curr->next->val == v) {
          curr->next = curr->next->next;
        }
      } else {
        curr = curr->next;
      }
    }
    return dummy->next;
  }
};
int main() {

  Solution test;
  return 0;
}
