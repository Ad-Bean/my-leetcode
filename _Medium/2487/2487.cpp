
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
给你一个链表的头节点 head 。

移除每个右侧有一个更大数值的节点。

返回修改后链表的头节点 head 。
输入：head = [5,2,13,3,8]
输出：[13,8]
解释：需要移除的节点是 5 ，2 和 3 。
- 节点 13 在节点 5 右侧。
- 节点 13 在节点 2 右侧。
- 节点 8 在节点 3 右侧。


方法一：栈 + 遍历两次
从左向右遍历，推入栈
此时 head 为 nullptr
从后往前找，第一步更新 head 为最后入栈
如果栈顶值大于当前头节点，则加入链表


方法二：单调栈
每次都把当前值入栈，维护单调递减
如果当前值比栈顶大，循环栈顶，表示不要这些值
如果栈为空，表示前面的值都小于当前，更新 dummy->next 为最新的头
如果栈不空，栈顶此时小于等于当前值，则更新 stk.top()->next = cur


方法二：反转链表
反转
不断地移除该节点的右侧节点，直到该节点的右侧节点值大于或等于该节点值。
再次反转
*/

class Solution {
 public:
  ListNode* removeNodes(ListNode* head) {
    ListNode* dummy = new ListNode(-1, head);
    vector<ListNode*> stk;
    for (ListNode* cur = head; cur; cur = cur->next) {
      while (!stk.empty() && stk.back()->val < cur->val) {
        stk.pop_back();
      }

      if (!stk.empty()) {
        stk.back()->next = cur;
      } else {
        dummy->next = cur;
      }
      stk.emplace_back(cur);
    }
    return dummy->next;
  }
};
int main() {

  Solution test;
  return 0;
}