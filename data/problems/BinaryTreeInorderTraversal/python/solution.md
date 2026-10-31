### Approach

Iterative inorder with an explicit stack. Go left as far as possible, pushing each node on the way. Pop a node, record it, then continue from its right child. The stack plays the role of the recursion's call stack.

### Implementation

```python
from typing import List
from treenode import TreeNode


class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        result = []
        stack = []
        node = root
        while node or stack:
            while node:
                stack.append(node)
                node = node.left
            node = stack.pop()
            result.append(node.val)
            node = node.right
        return result
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(h), where h is the height of the tree**.
