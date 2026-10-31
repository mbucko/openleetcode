### Approach

In a valid binary search tree the inorder traversal is increasing, so swapping two values creates one or two places where a value is smaller than the one before it. The first swapped value is the larger value at the first such drop. The second is the smaller value at the last drop. If the swapped nodes are next to each other in inorder, both come from the same drop.

### Implementation

```python
from typing import List
from treenode import TreeNode


class Solution:
    def recoverTree(self, root: TreeNode) -> List[int]:
        first = second = prev = None
        stack = []
        node = root
        while node or stack:
            while node:
                stack.append(node)
                node = node.left
            node = stack.pop()
            if prev is not None and node.val < prev.val:
                if first is None:
                    first = prev
                second = node
            prev = node
            node = node.right
        return sorted([first.val, second.val])
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(h), where h is the height of the tree**.
