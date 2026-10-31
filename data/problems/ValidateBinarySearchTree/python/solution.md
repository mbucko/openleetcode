### Approach

A tree is a valid binary search tree exactly when its inorder traversal is strictly increasing. Walk the tree in order with an explicit stack and compare each value with the previous one. Comparing nodes rather than starting from a sentinel value avoids trouble with values at the 32-bit limits.

### Implementation

```python
from treenode import TreeNode


class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        stack = []
        node = root
        prev = None
        while node or stack:
            while node:
                stack.append(node)
                node = node.left
            node = stack.pop()
            if prev is not None and node.val <= prev:
                return False
            prev = node.val
            node = node.right
        return True
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(h), where h is the height of the tree**.
