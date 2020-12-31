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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head): node_(head), head_(head) { }
    
    /** Returns a random node's value. */
    int getRandom() {
      uniform_int_distribution<int> distribution(1, 10'000);
      int steps = distribution(generator);
      for (int step = 0; step < steps; ++step) {
        if (node_)
          node_ = node_->next;
        if (!node_)
          node_ = head_;
      }
      return node_->val;
    }

  private:
    ListNode *node_, *head_;
    mt19937 generator;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
