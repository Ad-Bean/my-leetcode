#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

方法一：双指针
用一个指针表示 dummy 节点
另一个指针表示 curr 节点
遍历链表
每次先暂存 curr->next
将 curr->next 指向 dummy
更新 dummy 为 curr
更新 curr 为暂存的 curr->next

直到 curr 为空，此时 dummy 就为原链表的尾节点，新节点的头节点
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
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* dummy = nullptr;
    ListNode* curnt = head;
    while (curnt) {
      ListNode* tmp = curnt->next;
      curnt->next = dummy;
      dummy = curnt;
      curnt = tmp;
    }
    return dummy;
  }
};
int main() {

  Solution test;
  return 0;
}
