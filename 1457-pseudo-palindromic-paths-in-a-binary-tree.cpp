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
class Solution {
  public:
    vector<int> f;
  
    int pseudoPalindromicPaths(TreeNode* root, bool initial = true) {
      if (initial) {
        f.clear();
        f.resize(10);
      }
      if (!root)
        return 0;
      ++f[root->val];
      if (!root->left && !root->right) {
        int k = 0;
        for (int i = 1; i <= 9; ++i)
          if (f[i] & 1)
            ++k;
        --f[root->val];
        return k <= 1;
      }
      int left = pseudoPalindromicPaths(root->left, false);
      int right = pseudoPalindromicPaths(root->right, false);
      --f[root->val];
      return left + right;
    }
};
