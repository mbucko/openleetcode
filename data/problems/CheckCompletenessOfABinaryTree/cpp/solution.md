### Approach


### Implementation

```cpp
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        deque<TreeNode*> stack;
        stack.push_back(root);

        bool foundNull = false;
        while (!stack.empty()) {
            TreeNode* node = stack.front();
            stack.pop_front();

            if (node == nullptr) {
                foundNull = true;
                continue;
            } else {
                if (foundNull == true) {
                    return false;
                } else {
                    stack.push_back(node->left);
                    stack.push_back(node->right);
                }
            }
        }
        return true;
    }
};
```

### Complexity Analysis
* Time complexity : **O(N)**.<br>

* Space complexity : **O(log(N))**.<br>

