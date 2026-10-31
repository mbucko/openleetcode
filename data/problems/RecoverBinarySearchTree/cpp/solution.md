### Approach

In a valid binary search tree the inorder traversal is increasing, so swapping two values creates one or two places where a value is smaller than the one before it. The first swapped value is the larger value at the first such drop. The second is the smaller value at the last drop. If the swapped nodes are next to each other in inorder, both come from the same drop.

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
    vector<int> recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;
        vector<TreeNode*> stack;
        TreeNode* node = root;
        while (node || !stack.empty()) {
            while (node) {
                stack.push_back(node);
                node = node->left;
            }
            node = stack.back();
            stack.pop_back();
            if (prev && node->val < prev->val) {
                if (!first) {
                    first = prev;
                }
                second = node;
            }
            prev = node;
            node = node->right;
        }
        return {min(first->val, second->val), max(first->val, second->val)};
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(h), where h is the height of the tree**.
