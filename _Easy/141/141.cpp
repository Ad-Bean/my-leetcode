#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

/* 
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

方法一：快慢指针
快指针每次走两步，慢指针每次走一步
如果有环，快指针一定会追上慢指针
 

 */

class Solution {
 public:
  bool hasCycle(ListNode* head) {
    ListNode *l = head, *r = head;
    while (l && r && r->next) {
      l = l->next;
      r = r->next->next;
      if (l == r) {
        return true;
      }
    }
    return false;
  }
};
int main() {

  Solution test;
  return 0;
}
