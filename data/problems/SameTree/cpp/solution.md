### Approach

Compare recursively. Two empty trees are the same. If only one is empty, they differ. Otherwise the root values must match, and so must the left subtrees and the right subtrees.

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) {
            return p == q;
        }
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
```

### Complexity Analysis

* Time complexity: **O(min(m, n))**.
* Space complexity: **O(min(h1, h2)) recursion depth**.
