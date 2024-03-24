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
给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。

k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗？
输入：head = [1,2,3,4,5], k = 2
输出：[2,1,4,3,5]

方法一：反转链表
从头节点开始
记录一个 tail 节点表示第 i * k 个节点的尾节点
往前走 k 步，如果为空则直接返回头节点
此时将 head 到 tail 之间的链表反转，返回新的头节点和尾节点

 */
class Solution {

 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* dummy = new ListNode(-1, head);
    ListNode* pre = dummy;
    while (head) {
      ListNode* tail = pre;
      for (int i = 0; i < k; i++) {
        tail = tail->next;
        if (tail == nullptr) {
          return dummy->next;
        }
      }
      ListNode* next = tail->next;
      ListNode *prev = next, *curr = head;  // prev 接上原本 tail->next
      while (prev != tail) {                // 停止条件也变成了 prev != tail
        ListNode* t = curr->next;
        curr->next = prev;
        prev = curr;
        curr = t;
      }
      // 反转了 head 到 tail 之间的链表，且 tail 是反转后的头，head 是反转后的尾
      //   cout << "head: " << head->val << " tail: " << tail->val << endl;
      //   cout << "pre: " << pre->val << endl;
      //   cout << "next: " << next->val << endl;

      pre->next = tail;   // 接上新的头节点
      head->next = next;  // ?
      pre = head;         // 新的头节点
      head = head->next;  //
    }
    return dummy->next;
  }
};
int main() {

  Solution test;
  ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  ListNode* newHead = test.reverseKGroup(head, 2);
  while (newHead) {
    cout << newHead->val << " ";
    newHead = newHead->next;
  }
  cout << endl;
  return 0;
}