### Approach

Compare recursively. Two empty trees are the same. If only one is empty, they differ. Otherwise the root values must match, and so must the left subtrees and the right subtrees.

### Implementation

```python
from treenode import TreeNode


class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if p is None or q is None:
            return p is q
        return p.val == q.val and self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
```

### Complexity Analysis

* Time complexity: **O(min(m, n))**.
* Space complexity: **O(min(h1, h2)) recursion depth**.
