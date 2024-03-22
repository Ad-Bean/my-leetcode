#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个单链表的头节点 head ，请你判断该链表是否为 回文链表
如果是，返回 true ；否则，返回 false 。

数组做法：
将所有元素存入数组，然后双指针比较是否相同
时间复杂度 O(n + n / 2)
空间复杂度 O(n)

方法一：快慢指针
反转链表后半部分，空间复杂度 O(1)，但是会修改链表，不安全（需要锁防止其他修改）



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
  ListNode* reverse(ListNode* head) {
    ListNode *pre = nullptr, *cur = head;
    while (cur) {
      ListNode* t = cur->next;
      cur->next = pre;
      pre = cur;
      cur = t;
    }
    return pre;
  }

 public:
  bool isPalindrome(ListNode* head) {
    ListNode *l = head, *r = head;
    while (r->next && r->next->next) {
      l = l->next;
      r = r->next->next;
    }
    ListNode* rr = reverse(l->next);
    ListNode* ll = head;
    ListNode* temp = rr;
    bool isPal = true;  // to reverse back
    while (rr && isPal) {
      if (ll->val != rr->val) {
        isPal = false;
      }
      ll = ll->next;
      rr = rr->next;
    }
    reverse(temp);
    return isPal;
  }
};
int main() {

  Solution test;
  ListNode* r = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(1))));
  cout << test.isPalindrome(r) << endl;
  return 0;
}
