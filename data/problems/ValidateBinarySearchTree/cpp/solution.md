### Approach

A tree is a valid binary search tree exactly when its inorder traversal is strictly increasing. Walk the tree in order with an explicit stack and compare each value with the previous one. Comparing nodes rather than starting from a sentinel value avoids trouble with values at the 32-bit limits.

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
    bool isValidBST(TreeNode* root) {
        vector<TreeNode*> stack;
        TreeNode* node = root;
        TreeNode* prev = nullptr;
        while (node || !stack.empty()) {
            while (node) {
                stack.push_back(node);
                node = node->left;
            }
            node = stack.back();
            stack.pop_back();
            if (prev && node->val <= prev->val) {
                return false;
            }
            prev = node;
            node = node->right;
        }
        return true;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(h), where h is the height of the tree**.
