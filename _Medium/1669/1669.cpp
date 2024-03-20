#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你两个链表 list1 和 list2 ，它们包含的元素分别为 n 个和 m 个。

请你将 list1 中下标从 a 到 b 的全部节点都删除，并将list2 接在被删除节点的位置。

下图中蓝色边和节点展示了操作后的结果：


请你返回结果链表的头指针。

输入：list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
输出：[10,1,13,1000000,1000001,1000002,5]
解释：我们删除 list1 中下标为 3 和 4 的两个节点，并将 list2 接在该位置。上图中蓝色的边和节点为答案链表。

方法一：链表操作
遍历 a - 1 次找到 a 的前一个节点
遍历 b - a + 2 次找到 b 的后一个节点
将 a 的前一个节点指向 list2
遍历 list2 找到最后一个节点 while(list2->next) list2 = list2->next
将 list2 的最后一个节点指向 b 的后一个节点
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
  ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode* l = list1;
    int t = a;
    while (--t) {  // prev-> a -> ... ->
      l = l->next;
    }
    ListNode* r = l;
    int k = b - a + 1 + 1;  // a -> ... -> b -> next
    while (k--) {
      r = r->next;
    }
    l->next = list2;
    while (list2->next) {
      list2 = list2->next;
    }
    list2->next = r;
    return list1;
  }
};
int main() {

  Solution test;
  ListNode* list1 =
      new ListNode(10, new ListNode(1, new ListNode(13, new ListNode(6, new ListNode(9, new ListNode(5))))));
  ListNode* list2 = new ListNode(1000000, new ListNode(1000001, new ListNode(1000002)));
  ListNode* res = test.mergeInBetween(list1, 3, 4, list2);
  while (res) {
    cout << res->val << " ";
    res = res->next;
  }

  return 0;
}
