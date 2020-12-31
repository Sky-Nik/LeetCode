/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
  public:
    Node* connect(Node* root) {
      if (!root)
        return nullptr;
      deque<Node*> bfs = {root};
      while (!bfs.empty()) {
        int k = bfs.size();
        for (int i = 0; i + 1 < k; ++i) {
          bfs[i]->next = bfs[i + 1];
        }
        for (int i = 0; i < k; ++i) {
          auto node = bfs.front();
          bfs.pop_front();
          if (node->left)
            bfs.push_back(node->left);
          if (node->right)
            bfs.push_back(node->right);
        }
      }
      return root;
    }
};
