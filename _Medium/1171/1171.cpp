
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个链表的头节点 head，请你编写代码，反复删去链表中由 总和 值为 0 的连续节点组成的序列，
直到不存在这样的序列为止。

删除完毕后，请你返回最终结果链表的头节点。

 

你可以返回任何满足题目要求的答案。

（注意，下面示例中的所有序列，都是对 ListNode 对象序列化的表示。）
示例 1：

输入：head = [1,2,-3,3,1]
输出：[3,1]
提示：答案 [1,2,1] 也是正确的。
示例 2：

输入：head = [1,2,3,-3,4]
输出：[1,2,4]
示例 3：

输入：head = [1,2,3,-3,-2]
输出：[1]

方法一：前缀和 + 哈希表
遍历链表，计算前缀和，并且记录 mp[pre] = node
再次遍历链表，计算前缀和，node->next = mp[pre]->next
表示如果 pre 出现过，那么 pre 到当前节点的和为 0
  比如 1 2 -3 3 1
前缀和 1 3 0 3 4
1 没出现过，node->next = node->next 不变
3 出现过并且被覆盖，node->next = mp[3]->next = 3->next = 3 1

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
  ListNode* removeZeroSumSublists(ListNode* head) {
    int pre = 0;
    unordered_map<int, ListNode*> mp;
    ListNode* dummy = new ListNode(0, head);
    ListNode* node = dummy;
    while (node) {
      pre += node->val;
      mp[pre] = node;
      node = node->next;
    }
    pre = 0;
    node = dummy;
    while (node) {
      pre += node->val;
      node->next = mp[pre]->next;
      node = node->next;
    }
    return dummy->next;
  }
};

int main() {

  Solution test;
  return 0;
}