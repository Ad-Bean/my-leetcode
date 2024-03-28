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
将两个升序链表合并为一个新的 升序 链表并返回。

新链表是通过拼接给定的两个链表的所有节点组成的。 

 */
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode(-1);
    ListNode* current = dummy;
    while (list1 || list2) {
      if (list1 == nullptr) {
        current->next = list2;
        break;
      }
      if (list2 == nullptr) {
        current->next = list1;
        break;
      }
      if (list1->val < list2->val) {
        current->next = list1;
        current = current->next;
        list1 = list1->next;
      } else {
        current->next = list2;
        current = current->next;
        list2 = list2->next;
      }
    }
    return dummy->next;
  }
};
int main() {

  Solution test;
  return 0;
}
