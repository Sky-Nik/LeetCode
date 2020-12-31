/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
  public:
    BSTIterator(TreeNode* root) {
      path_.emplace(root, 0);
    }
    
    int next() {
      if (ready != -1) {
        int answer = ready;
        ready = -1;
        return answer; 
      }
      while (!path_.empty()) {
        auto& [node, visit_time] = path_.top();
        if (visit_time == 0) {
          if (node->left) {
            path_.emplace(node->left, 0);
          } else {
            ++visit_time;
            ready = -1;
            return node->val;
          }
        } 
        if (visit_time == 1) {
          if (node->right) {
            path_.emplace(node->right, 0);
          } else {
            ++visit_time;
          }
        } 
        if (visit_time == 2) {
          path_.pop();
          if (!path_.empty()) {
            ++path_.top().second;
            if (path_.top().second == 1) {
              ready = -1;
              return path_.top().first->val;
            }
          }
        }
      }
      return -1;
    }
    
    bool hasNext() {
      ready = next();
      return ready != -1;
    }

  private:
    int ready = -1;
    stack<pair<TreeNode*, int>> path_;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
