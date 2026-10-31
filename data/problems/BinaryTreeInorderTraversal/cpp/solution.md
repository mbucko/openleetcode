### Approach

Iterative inorder with an explicit stack. Go left as far as possible, pushing each node on the way. Pop a node, record it, then continue from its right child. The stack plays the role of the recursion's call stack.

### Implementation

```cpp
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        vector<TreeNode*> stack;
        TreeNode* node = root;
        while (node || !stack.empty()) {
            while (node) {
                stack.push_back(node);
                node = node->left;
            }
            node = stack.back();
            stack.pop_back();
            result.push_back(node->val);
            node = node->right;
        }
        return result;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(h), where h is the height of the tree**.
