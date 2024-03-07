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
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

方法一：快慢指针
快指针每次走两步，慢指针每次走一步，快指针走到末尾，慢指针走到中间
 */
class Solution {
 public:
  ListNode* middleNode(ListNode* head) {
    ListNode *l = head, *r = head;
    while (r && r->next) {
      l = l->next;
      r = r->next->next;
    }
    return l;
  }
};
int main() {

  Solution test;
  return 0;
}
