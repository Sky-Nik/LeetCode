/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
    ListNode* swapPairs(ListNode* head) {
      auto new_head = (head && head->next) ? head->next : head; 
      auto node = head;
      if (node && node->next)
        tie(node, node->next, node->next->next) = \
          make_tuple(node->next->next, swapPairs(node->next->next), node);
      return new_head;
    }
};
